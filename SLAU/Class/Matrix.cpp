#include "Matrix.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

double Matrix::compulationAij(int i = 1, int j = 1)
{
	double a_temp = a, b_temp = b;
	double resultPrev = GaussIntegral(i + 1, j + 1, &Matrix::thetaA, a_temp, b_temp); // делим на два отрезка и суммируем
	double resultLast = GaussIntegral(i + 1, j + 1, &Matrix::thetaA, a_temp, (b_temp - a_temp) / 2);
	resultLast += GaussIntegral(i + 1, j + 1, &Matrix::thetaA, (b_temp - a_temp) / 2, b_temp);
	int count = 3; // 3 деления
	double delta;

	while (abs(resultLast - resultPrev) > eps) {
		delta = (b_temp - a_temp) / count;
		resultPrev = resultLast;
		resultLast = 0;
		for (int q1 = 0; q1 < count; q1++)
			resultLast += GaussIntegral(i + 1, j + 1, &Matrix::thetaA, a_temp + q1 * delta, a_temp + (q1 + 1) * delta);
		count++;
	}
	return resultLast;
}

double Matrix::compulationBj(int i = 1)
{
	double a_temp = a, b_temp = b;
	double resultPrev = GaussIntegral(i + 1, 0, &Matrix::thetaB, a_temp, b_temp); // делим на два отрезка и суммируем
	double resultLast = GaussIntegral(i + 1, 0, &Matrix::thetaB, a_temp, (b_temp - a_temp) / 2.0);
	resultLast += GaussIntegral(i + 1, 0, &Matrix::thetaB, (b_temp - a_temp) / 2, b_temp);
	int count = 3; // 3 деления
	double delta;

	while (abs(resultLast - resultPrev) > eps) {
		delta = (b_temp - a_temp) / count;
		resultPrev = resultLast;
		resultLast = 0;
		for (int q1 = 0; q1 < count; q1++)
			resultLast += GaussIntegral(i + 1, 0, &Matrix::thetaB, a_temp + q1 * delta, a_temp + (q1 + 1) * delta);
		count++;
	}
	return resultLast;
}

double Matrix::GaussIntegral(int i, int j, function f2, double a0, double b0)
{
	double x_point[4];
	for (int q1 = 0; q1 < nR; q1++)
		x_point[q1] = (b0 + a0) / 2.0 + (b0 - a0) / 2.0 * t[q1];
	double sum = 0;
	double aq1 = 0;
	for (int q1 = 0; q1 < nR; q1++) {
		aq1 = (this->*f2)(x_point[q1], i, j);
		sum += c[q1] * aq1;
	}
	return (b0 - a0) / 2.0 * sum;
}

 Matrix::Matrix() {
	begin = nullptr;
	n = 0;
	m = 0;
	permut = 0;
	det = 1;

	PI = acos(-1);
	nR = N = a = b = dl = mu1 = mu2 = 0;
	c[0] = c[1] = c[2] = c[3] = 0;
	t[0] = t[1] = t[2] = t[3] = 0;
}

 Matrix::Matrix(int n,int m) {
	 begin = nullptr;
	 n = 0;
	 m = 0;
	 permut = 0;
	 det = 1;

	 PI = acos(-1);
	 nR = N = a = b = dl = mu1 = mu2 = 0;
	 c[0] = c[1] = c[2] = c[3] = 0;
	 t[0] = t[1] = t[2] = t[3] = 0;

	 Create(n, m);
 }


Matrix::Matrix(const Matrix& temp) {
	this->n = temp.n;
	this->m = temp.m;
	this->det = temp.det;
	this->permut = temp.permut;
	this->begin = new double * [this->n];

	PI = acos(-1);
	this->nR = temp.nR;
	this->N = temp.N;
	this->a = temp.a;
	this->b = temp.b;
	this->dl = temp.dl;
	this->mu2 = temp.mu2;
	this->mu1 = temp.mu1;
	for (int i = 0; i < 4; i++) {
		this->c[i] = temp.c[i];
		this->t[i] = temp.t[i];
	}

	for (int i = 0; i < this->n; i++) {
		this->begin[i] = new double [this->m] ;
		for (int j = 0; j < this->m; j++) {
			this->begin[i][j] = temp.begin[i][j];
		}
	}
}

Matrix::Matrix(double** temp, int n, int m)
{
	this->n = n;
	this->m = m;
	this->det = 0;
	this->permut = 0;

	PI = acos(-1);
	nR = N = a = b = dl = mu1 = mu2 = 0;
	c[0] = c[1] = c[2] = c[3] = 0;
	t[0] = t[1] = t[2] = t[3] = 0;

	begin = new double* [n];
	for (size_t i = 0; i < n; i++)
	{
		begin[i] = new double[m];

		for (size_t j = 0; j < m; j++)
		{
			begin[i][j] = temp[i][j];
		}
	}
	this->begin = begin;
}

Matrix::~Matrix(void){
	if (begin != nullptr) {
		for (int i = 0; i < n; i++) {
			delete begin[i];
		}
		delete begin;
	}
}

double Matrix::GetDet()
{
	return det;
}

void Matrix :: Create() {
	cout << "1) Заполнить внутри класса\n\n2) Чтение из файла\nДругое значение - чтение из file.txt\n>> ";
	int x;
	char a[100];

	if (begin != nullptr) {
		for (int i = 0; i < this->n; i++)
			delete begin[i];
		delete begin;
	}

	cin >> x;

	switch (x) {
	case(1):
		cout << "Введите размерность массива/\n";
		cout << "n: "; cin >> n;
		cout << "m: "; cin >> m;
		Create(n, m);
	case(2):
		cout << "Введите путь к файлу.\nФайл должен иметь вид: int n int m double[n][m]\nСперва имеет 2 целых числа, а потом матрицу. Путь << ";
		cin>>a;
		ReadFile(a);
		break;
	default:
		cout << "Вы ничего из списка не выбрали, поэтому заполним из файла A.txt, котоая лежит в директории программы.\n";
		ReadFile((char*)"A.txt");
		break;
	}
}

void Matrix::Create(char* S) {
	ReadFile(S);
}

 void Matrix::Create(int n, int m) {
	//cout << "Заполнение массива\n";
	if (n < 1 || m < 1)
		throw "n|m < 1";
	if (begin != nullptr) {
		for (int i = 0; i < this->n; i++)
			delete begin[i];
		delete begin;
	}
	this->n = n;
	this->m = m;
	if(begin == nullptr)
		begin = new double* [n];
	
	cout << "1) Заполнить самому\n2) Заполнить случайным образом\n>> ";
	int x;
	cin >> x;

	switch (x) {
	case(1):
		for (int i = 0; i < n; i++)
		{
			begin[i] = new double[m];
			for (int j = 0; j < m; j++)
			{
				cout << "[" << i << "][" << j << "] = ";
				cin >> begin[i][j];
				cout << endl;
			}
		}
		break;
	case(2):
		for (int i = 0; i < n; i++)
		{
			begin[i] = new double[m];
			for (int j = 0; j < m; j++)
			{
				//cout << "[" << i << "][" << j << "] = "; 
				begin[i][j]=rand()%1000/100.0;
				//cout << begin[i][j];
				//cout << endl;
			}
		}
		break;
	default:
		cout << "Вы ничего из списка не выбрали, поэтому заполним случайным образом.\n";

		for (int i = 0; i < n; i++)
		{
			begin[i] = new double[m];
			for (int j = 0; j < m; j++)
			{
				//cout << "[" << i << "][" << j << "] = "; 
				begin[i][j] = rand() % 1000 / 100.0;
				//cout << begin[i][j];
				//cout << endl;
			}
		}
		break;
	}
}

 void Matrix::CreateNULL(int n, int m) {
	//cout << "Заполнение массива\n";
	if (n < 1 || m < 1)
		throw "n|m < 1";
	
	if (begin != nullptr) {
		for (int i = 0; i < this->n; i++)
			delete begin[i];
		delete begin;
	}
	
	this->n = n;
	this->m = m;
	
	begin = new double* [n];
	for (int i = 0; i < n; i++)
	{
		begin[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			begin[i][j]=0;
		}
	}
}

 void Matrix::CreateOnes(int n, int m)
 {
	 if (n < 1 || m < 1)
		 throw "n|m < 1";
	 this->n = n;
	 this->m = m;
	 if (begin == nullptr)
		 begin = new double* [n];
	 for (int i = 0; i < n; i++)
	 {
		 begin[i] = new double[m];
		 for (int j = 0; j < m; j++)
		 {
			 begin[i][j] = 1;
		 }
	 }
 }

 void Matrix::CreatePoly(char a,int n)
 {
	 if (begin != nullptr) {
		 for (size_t i = 0; i < n; i++)
		 {
			 delete begin[i];
		 }
		 delete begin;
	 }
	 this->m = 1;
	 this->n = 10;
	 begin = new double* [10];

	 switch (a) {
	 case 'x':
		 for (size_t i = 0; i < 10; i++)
		 {
			 begin[i] = new double[1];
			 begin[i][0] = 0.1 * (3 + i + n);
		 }
		 break;
	 case 'y':
		 for (size_t i = 0; i < 10; i++)
		 {
			 begin[i] = new double[1];
		 }
		 begin[0][0] = 0.5913;
		 begin[1][0] = 0.63+n/17;
		 begin[2][0] = 0.7162;
		 begin[3][0] = 0.8731;
		 begin[4][0] = 0.9574;
		 begin[5][0] = 1.8-cos(n/11);
		 begin[6][0] = 1.3561;
		 begin[7][0] = 1.2738;
		 begin[8][0] = 1.1+n/29;
		 begin[9][0] = 1.1672;
		 break;
	 }
 }
 
 void Matrix::CreateDiagonal(int n) {
	//cout << "Заполнение массива\n";
	if (n < 1)
		throw "n< 1";
	this->n = n;
	this->m = n;
	if (begin == nullptr)
		begin = new double* [n];
	for (int i = 0; i < n; i++)
	{
		begin[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			if (i == j) begin[i][j] = 1;
			else
				begin[i][j]=0;
		}
	}
}


void Matrix::Show() {
	Show(2);
}

void Matrix::Show(Matrix &temp) {
	Show(temp, 2);
}

void Matrix::Show(int x) {
	//cout << "Вывод массива\n";
	cout << fixed;
	cout.precision(x);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "[" << begin[i][j];
			cout << "]\t";
		}
		cout << endl;
	}
}

void Matrix::Show(Matrix& temp,int x) {
	if (n != temp.n || m != temp.m)
		throw "n or m != temp.n or temp.m";

	cout << fixed;
	cout.precision(x);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "F(" << temp.begin[i][j];
			cout << ") = " << begin[i][j] << endl;
		}
	}
}

void Matrix::ShowAll(int x)
{
	//cout << "Вывод массива\n";
	cout << fixed;
	cout.precision(x);
	cout << "Matrix [";
	cout << this->n;
	cout << "][";
	cout << this->m;
	cout << "]\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "[" << begin[i][j];
			cout << "]   \t";
		}
		cout << endl;
	}
	cout << "a: " << a << ", b: " << b << ", dl: " << dl << ", mu1: " << mu1 << ", mu2: " << mu2 << endl;
	cout << "c: "; for (unsigned short i = 0; i < 4; i++) cout << c[i] << " ";
	cout << "\nt: "; for (unsigned short i = 0; i < 4; i++) cout << t[i] << " ";
	cout << endl << "eps: " << eps << endl;
}

 Matrix& Matrix::operator*(Matrix& temp) {
	 //cout << "[" << n << "][" << m << "] ? [" << temp.n << "][" << temp.m << "]" << endl;
	if (this->m != temp.n) {
		throw "m != temp.n";
	}
	Matrix *A=new Matrix();
	A->CreateNULL(n, temp.m);
	for (int i = 0; i < A->n; i++){
		for (int j = 0; j < A->m; j++) {
			for (int x = 0; x < m; x++)
			{
				A->begin[i][j] += begin[i][x] * temp.begin[x][j];
			}
		}
	}
	return *A;
}

 bool Matrix::operator==(Matrix& temp)
 {
	 if (n != temp.n || m != temp.m)
		 throw "Length";

	 for (size_t i = 0; i < n; i++)
	 {
		 for (size_t j = 0; j < m; j++)
		 {
			 if (begin[i][j] != temp.begin[i][j]) return false;
		 }
	 }
	 return true;
	 // TODO: вставьте здесь оператор return
 }

 bool Matrix::operator!=(Matrix& temp)
 {
	 if (temp == *this)
		 return false;
	 else return true;
 }

 /*Matrix& Matrix::MethodGauss_byrow(Matrix& rightTemp)
 {
	 if (n != m || rightTemp.m!=1)
		 throw"n!=m  || right.m!=1";
	 Matrix ite;
	 ite.CreateNULL(n, 1);
	 for (size_t i = 0; i < n; i++)
	 {
		 ite.begin[i][0] = i;
	 }
	 Matrix right = rightTemp;
	 Matrix temp(*this);
	 // Создаем решение СЛАУ
	 double a12 = 0;

	 for (int i = 0; i < n-1; ++i) {
		 // Инициализация главного элемента. Изначально он находится в матрице А с индексами [0][0]
		 double MaxEl = temp.begin[i][i];
		 int iMaxEl = i;

		 // Поиск индекса главного элемента
		 for (int j = 0; j < n-i; ++j) {
			 // Если следующий элемент в строке по модулю больше, чем текущий главный элемент, то обновляем его
			 if (abs(MaxEl) < abs(temp.begin[j+i][i])) {
				 MaxEl = temp.begin[j+i][i];
				 iMaxEl = j+i;
			 }
		 }
		 // Меняем 1 строку на строку с главным элементом в обоих матрицах
		 if (iMaxEl != i) {
			 for (size_t j = 0; j < n; j++)
			 {
				 a12 = temp.begin[i][j];
				 temp.begin[i][j] = temp.begin[iMaxEl][j];
				 temp.begin[iMaxEl][j] = a12;
			 }
			 a12 = right.begin[i][0];
			 right.begin[i][0] = right.begin[iMaxEl][0];
			 right.begin[iMaxEl][0] = a12;
			 
			 a12 = ite.begin[i][0];
			 ite.begin[i][0] = ite.begin[iMaxEl][0];
			 ite.begin[iMaxEl][0] = a12;
		 }


		 //cout << endl << endl;
		 //temp.Show();

		 // Делим строку на главный элемент
		 // Проверяем, не является ли 2 матрица вектором
		 
		 right.begin[i][0] /= temp.begin[i][i];
		 
		 for (size_t j = i; j < n; j++)
		 {
			 temp.begin[i][j] /= temp.begin[i][i];
		 }

		 // Приводим к верхне-угольной матрице матрицу A
		 if (i != n - 1) {

			 for (size_t j = i+1; j < n; j++)
			 {
				 right.begin[j][0] -= temp.begin[i][i]*right.begin[i][0];
				 for (size_t j2 = i; j2 < n; j2++)
				 {
					 temp.begin[j][j2] -= temp.begin[i][j2] * temp.begin[j][j2];
				 }
			 }
		 }
		 cout << endl << endl;
		 temp.Show();

	 }

	 // Нахождение решения 'x' системы линейных алгебраических уравнений Ax=f
	 //for (int i = n - 1; i >= 0; --i) {
		// double coeff_multiply = 0.0;
		// for (int j = i; j < n; ++j) {
		//	 coeff_multiply += temp.begin[i][j] * X->begin[j][0];
		//	 X->begin[i][0] = (right.begin[i][0] - coeff_multiply) / temp.begin[i][i];
		// }
	 //}

	 ////                    ***** 3 Задание *****
	 //// Задание 3. Нахождение определителя матрицы методом Гаусса
	 //double value_det = temp.begin[0][0];
	 //// Так как матрица у нас верхнетреугольная, после преобразований.
	 //// То определитель равен произведению всех диагональных элементов матрицы, с учетом перестановок
	 //for (int i = 1; i < n; ++i) {
		// value_det *= temp.begin[i][i];
	 //}
	 //det = pow(-1, permut) * value_det;
	 //return *X;
 }*/

 Matrix& Matrix::MethodGauss_bycolumn(Matrix& rightTemp)
 {
	 if (n != m || rightTemp.m != 1)
		 throw"n!=m  || right.m!=1";

	 int* ite = new int[n]; // Чтобы знать новый порядок строк, например x2+x5+x1 ...

	 for (size_t i = 0; i < n; i++)
	 {
		 ite[i] = i;
	 }
	 
	 Matrix right = rightTemp; // Правая матрица - b
	 Matrix temp(*this); // Левая матрица - A
	 // Создаем решение СЛАУ
	 Matrix* X = new Matrix(rightTemp); // Матрица - x
	 X->CreateNULL(n, 1); // Создаем на n чисел
	 double a12 = 0; // Для изменения местами 2-х чисел
	 double MainEl; // Главный элемент в строке
	 int iMainEl; // Индекс главного элемента


	 for (int i = 0; i < n; ++i) {
		 // Инициализация главного элемента. Изначально он находится в матрице А на главной деагонали
		 MainEl = temp.begin[i][i];
		 iMainEl = i;

		 // Поиск индекса главного элемента
		 for (int j = i; j < n; ++j) {
			 // Если следующий элемент в строке по модулю больше, чем текущий главный элемент, то обновляем его
			 if (abs(MainEl) < abs(temp.begin[i][j])) {
				 MainEl = temp.begin[i][j];
				 iMainEl = j;
			 }
		 }
		 // Если главный элемент стоит на главной диагонали, то ничего не меняем местами, а сразу делаем итерацию методом Гаусса
		 if (iMainEl != i) {
			 // Увеличиваем количество перестановок
			 permut++;
			 // Меняем столбцы матрицы А местами
			 for (int k = 0; k < n; ++k) {
				 a12 = temp.begin[k][i];
				 temp.begin[k][i] = temp.begin[k][iMainEl];
				 temp.begin[k][iMainEl]=a12;
			 }
			 a12 = ite[i];
			 ite[i] = ite[iMainEl];
			 ite[iMainEl] = a12;
			 /*cout << "ite: ";
			 for (size_t i = 0; i < n; i++)
			 {
				 cout << ite[i] << " ";
			 }cout << endl;*/
		 }
		/* cout << "iM: " << iMainEl << ", i: " << i << endl;
		 cout << "temp:\n";
		 temp.Show();*/

		 // Элементарные преобразования. Прямой ход метода Гаусса
		 for (int k = i + 1; k < n; ++k) {
			 double coeff_multiply = -(temp.begin[k][i] / temp.begin[i][i]);
			 right.begin[k][0] += coeff_multiply * right.begin[i][0];
			 for (int j = 0; j < n; ++j) {
				 temp.begin[k][j] += coeff_multiply * temp.begin[i][j];
			 }
		 }
	 }

	 // Нахождение решения 'x' системы линейных алгебраических уравнений Ax=f
	 for (int i = n - 1; i >= 0; --i) {
		 double coeff_multiply = 0.0;
		 for (int j = i; j < n; ++j) {
			 coeff_multiply += temp.begin[i][j] * X->begin[j][0];
		 }
		 X->begin[i][0] = (right.begin[i][0] - coeff_multiply) / temp.begin[i][i];
	 }
	 /*a12=X->begin[1][0];
	 X->begin[1][0]= X->begin[2][0];
	 X->begin[2][0] = a12;*/

	 // Задание 3. Нахождение определителя матрицы методом Гаусса
	 double value_det = temp.begin[0][0];
	 // Так как матрица у нас верхнетреугольная, после преобразований.
	 // То определитель равен произведению всех диагональных элементов матрицы, с учетом перестановок
	 
	 int a13 = 0;
	 
	 // Мы меняли местами x1,x2 ..., теперь вернем порядок
	 bool bl1 = false;
	 while (true) { // Возвращаем 'x1','x2',.. на свое место (x4,x3,x1,x2 -> x1x2x3x4)
		 bl1 = false;
		 for (size_t i = 0; i < n - 1; i++)
		 {
			 if (ite[i] > ite[i + 1]) bl1 = true;
		 }
		 if (bl1) {
			 for (size_t i = 0; i < n; i++)
			 {
				 if (ite[i] != i) {
					 a12 = X->begin[i][0];
					 X->begin[i][0] = X->begin[ite[i]][0];
					 X->begin[ite[i]][0] = a12;

					 a13 = ite[ite[i]];
					 ite[ite[i]] = ite[i];
					 ite[i] = a13;
				 }
			 }
		 }
		 else {
			 break;
		 }
	 }

	 for (int i = 1; i < n; ++i) {
		 value_det *= temp.begin[i][i];
	 }
	 det = pow(-1, permut) * value_det;
	 return *X;
 }

 Matrix& Matrix::InverseGauss()
 {
	 if (n != m) throw "Inverse n!=m";
	 Matrix temp;
	 //cout << "temp diag: " << endl;
	 temp.CreateDiagonal(n);
	 //temp.Show();
	 Matrix* R=nullptr;
	 Matrix X;
	 Matrix* Y=new Matrix();
	 Y->CreateNULL(n, n);

	 double** A1 = nullptr;

	 for (size_t i1 = 0; i1 < n; i1++)
	 {
		 if (A1 != nullptr) {
			 for (size_t i = 0; i < n; i++)
			 {
				 delete A1[i];
			 }
			 delete A1;
			 A1 = nullptr;
		 }
		 
		 A1 = new double* [temp.n];
		 for (size_t i = 0; i < n; i++)
		 {
			 A1[i] = new double[1];
			 A1[i][0] = temp.begin[i1][i];
		 }
		 R = new Matrix(A1, n, 1);
		 X=MethodGauss_bycolumn(*R); // Нахождение i1-й колонки
		 delete R;
		 for (size_t i = 0; i < n; i++)
		 {
			 Y->begin[i][i1] = X.begin[i][0];
		 }
	 }
	 return *Y;
 }

 Matrix& Matrix::MethodHoleckogo(Matrix& right)
 {
	 Matrix A = *this;
	 if (*this != A.Transp()) {
		 cout << "MethodKVKornya: Transp '!='\n";
		 return *this;
	 }
	 Matrix L;
	 L.CreateNULL(n, m);
	 Matrix LT;
	 Matrix b = right;
	 Matrix y;
	 y.CreateNULL(b.n, b.m);
	 Matrix* x;
	 x = new Matrix(y);

	 for (size_t i = 0; i < n; i++)
	 {
		 L.begin[i][i] = A.begin[i][i]; // Беру a[i][i]

		 for (size_t j = 0; j < i; j++)
		 {
			 L.begin[i][i] -= pow(L.begin[i][j], 2); // Отнимаю элементы слева от l[i][i]
		 }

		 L.begin[i][i] = sqrt(L.begin[i][i]); // беру под корень

		 for (size_t j = i + 1; j < n; j++) // Ухожу вниз
		 {
			 L.begin[j][i] = A.begin[j][i];

			 for (size_t ij = 0; ij < i; ij++)
			 {
				 L.begin[j][i] -= L.begin[j][ij] * L.begin[i][ij];
			 }
			 L.begin[j][i] /= L.begin[i][i];
		 }
	 }

	 for (size_t i = 0; i < L.n; i++)
	 {
		 y.begin[i][0] = b.begin[i][0];
		 for (size_t j = 0; j < i; j++)
		 {
			 y.begin[i][0] -= (L.begin[i][j] * y.begin[j][0]);
		 }
		 y.begin[i][0] /= L.begin[i][i];
	 }

	 LT = L;
	 LT.Transp();

	 for (int i = LT.n - 1; i >= 0; i--)
	 {
		 x->begin[i][0] = y.begin[i][0];
		 for (size_t j = LT.m - 1; j > i; j--)
		 {
			 x->begin[i][0] -= (LT.begin[i][j] * x->begin[j][0]);
		 }
		 x->begin[i][0] /= LT.begin[i][i];
	 }

	 /*cout << "x: " << endl;
	 x->Show();
	 cout << "x Gauss: " << endl;
	 (LT.MethodGauss_bycolumn(L.MethodGauss_bycolumn(b))).Show();*/

	 return *x;
 }

 Matrix& Matrix::MethodYakobi(Matrix& F, Matrix& x, const double eps)
 {
	 Matrix TempX;
	 TempX.CreateNULL(n, 1);
	 Matrix* y = new Matrix(x);
	 double norm = 0;
	 size_t countoperation = 0;
	 do {
		 countoperation++;
		 for (int i = 0; i < n; i++) {
			 TempX.begin[i][0] = F.begin[i][0];
			 for (int g = 0; g < n; g++) {
				 if (i != g)
					 TempX.begin[i][0] -= begin[i][g] * y->begin[g][0];
			 }
			 TempX.begin[i][0] /= begin[i][i];
		 }
		 //cout << "TempX: [" << countoperation << endl;
		 //TempX.Show(20);
		  if (norm == 0)
			  norm = fabs(y->NormaVector(2) - TempX.NormaVector(2));

		  if (norm > fabs(y->NormaVector(2) - TempX.NormaVector(2)))
			  norm = fabs(y->NormaVector(2) - TempX.NormaVector(2));

		  for (size_t i = 0; i < n; i++)
		  {
			  y->begin[i][0] = TempX.begin[i][0];
		  }
		  //cout << "y: " << endl;
		  //y->Show(20);

		 /*norm = fabs(y->begin[0][0] - TempX.begin[0][0]);

		 for (int h = 0; h < n; h++) {
			 if (fabs(y->begin[h][0] - TempX.begin[h][0]) > norm)
				 norm = fabs(y->begin[h][0] - TempX.begin[h][0]);
			 y->begin[h][0] = TempX.begin[h][0];
		 }*/
	 } while (norm > eps && countoperation < x.n);
	 cout << "Count of operations in Method Yakobi: " << countoperation << endl;
	 return *y;
	 // TODO: вставьте здесь оператор return
 }

 Matrix& Matrix::MethodKVKor(Matrix& right)
 {
	 Matrix A = *this;
	 if (*this != A.Transp()) {
		 cout << "MethodKVKornya: Transp '!='\n";
		 return *this;
	 }
	 Matrix L;
	 L.CreateNULL(n, m);
	 Matrix LT;
	 Matrix b = right;
	 Matrix y;
	 y.CreateNULL(b.n, b.m);
	 Matrix* x;
	 x = new Matrix(y);

	 for (size_t i = 0; i < n; i++)
	 {
		 L.begin[i][i] = A.begin[i][i]; // Беру a[i][i]

		 for (size_t j = 0; j < i; j++)
		 {
			 L.begin[i][i] -= pow(L.begin[i][j], 2); // Отнимаю элементы слева от l[i][i]
		 }

		 L.begin[i][i] = sqrt(L.begin[i][i]); // беру под корень

		 for (size_t j = i + 1; j < n; j++) // Все нижние зануляются и получается нижнетреугольная матрица
		 {
			 L.begin[j][i] = A.begin[j][i];

			 for (size_t ij = 0; ij < i; ij++)
			 {
				 L.begin[j][i] -= L.begin[j][ij] * L.begin[i][ij];
			 }
			 L.begin[j][i] /= L.begin[i][i];
		 }
	 }

	 for (size_t i = 0; i < L.n; i++) // Вычисляется L*y=b
	 {
		 y.begin[i][0] = b.begin[i][0];
		 for (size_t j = 0; j < i; j++)
		 {
			 y.begin[i][0] -= (L.begin[i][j] * y.begin[j][0]);
		 }
		 y.begin[i][0] /= L.begin[i][i];
	 }

	 LT = L;
	 LT.Transp();

	 for (int i = LT.n - 1; i >= 0; i--) // Вычисляется LT*x=y
	 {
		 x->begin[i][0] = y.begin[i][0];
		 for (size_t j = LT.m - 1; j > i; j--)
		 {
			 x->begin[i][0] -= (LT.begin[i][j] * x->begin[j][0]);
		 }
		 x->begin[i][0] /= LT.begin[i][i];
	 }

	 return *x;
 }

 Matrix& Matrix::MethodGaussZeydel(Matrix& F, Matrix& x,const double eps)
 {
	 Matrix TempX; // Будем сохранять предыдущий вектор
	 Matrix* y = new Matrix(x); // Будем получать новый вектор
	 double norm = 0;
	 size_t countoperation = 0;
	 double var = 0;
	 do {
		 countoperation++;
		 TempX = *y;
		 for (size_t i = 0; i < n; i++)
		 {
			 var = 0;
			 for (size_t j = 0; j < n; j++)
				if (j != i)	// Сумма A[i,j] * X[j](k+1) |j=1,..,i-1| + A[i,j] * X[j](k) |j=i+1,..,n|
					var += (begin[i][j] * y->begin[j][0]); // Вычисляем коэффициент для нового вектора
			 y->begin[i][0] = (F.begin[i][0] - var) / begin[i][i]; // (B[i] - var)/A[i][i]
			 norm = abs(y->NormaVector(0)-TempX.NormaVector(0)); // Вычисляем векторную норму
			 //cout << "norma: "<<norm << endl;
		 }
		 //y->Show(8);
	 } while (norm > eps);
	 cout << "Количество операций: " << countoperation << endl;
	 return *y;
 }

 Matrix& Matrix::Integer(void)
 {
	 Matrix* X = new Matrix(*this);
	 for (size_t i = 0; i < n; i++)
	 {
		 for (size_t j = 0; j < m; j++)
		 {
			 modf(begin[i][j],&begin[i][j]);
			 begin[i][j] *= 1000;
		 }
	 }
	 return *X;
 }

 Matrix& Matrix::Okrugl(void)
 {
	 Matrix* X = new Matrix(*this);
	 for (size_t i = 0; i < n; i++)
	 {
		 for (size_t j = 0; j < m; j++)
		 {
			 X->begin[i][j] = floor(begin[i][j]);
		 }
	 }
	 return *X;
 }

 Matrix& Matrix::MethodYakobi(double x, double y, double z)
 {
	 Matrix* temp = new Matrix();
	 temp->CreateNULL(3,3);
	 temp->begin[0][0] = 2 * x + 1;
	 temp->begin[0][1] = -2 * z;
	 temp->begin[0][2] = -2 * y;

	 temp->begin[1][0] = 3 * z;
	 temp->begin[1][1] = 1 - 2 * y;
	 temp->begin[1][2] = 3 * x;

	 temp->begin[2][0] = 2 * y;
	 temp->begin[2][1] = 2 * x;
	 temp->begin[2][2] = 1 + 2 * z;
	 return *temp;
 }

 Matrix& Matrix::MethodSeidel(Matrix& TX,const double eps)
 {
	 Matrix* newX = new Matrix();
	 Matrix lastX = TX;
	 newX->CreateNULL(lastX.n,1);

	 newX->begin[0][0] = F1_S(lastX.begin[0][0], lastX.begin[1][0], lastX.begin[2][0]);
	 newX->begin[1][0] = F2_S(newX->begin[0][0], lastX.begin[1][0], lastX.begin[2][0]);
	 newX->begin[2][0] = F3_S(newX->begin[0][0], newX->begin[1][0], lastX.begin[2][0]);

	 int countoperation = 0;
	 
	 /*cout << "newX: "<<endl;
	 newX->Show();
	 cout << "lastX: " << endl;
	 lastX.Show();*/

	 while (max(*newX, lastX) > eps) {
		 lastX = *newX;
		 newX->begin[0][0] = F1_S(lastX.begin[0][0], lastX.begin[1][0], lastX.begin[2][0]);
		 newX->begin[1][0] = F2_S(newX->begin[0][0], lastX.begin[1][0], lastX.begin[2][0]);
		 newX->begin[2][0] = F3_S(newX->begin[0][0], newX->begin[1][0], lastX.begin[2][0]);
		 countoperation++;
	 }
	 cout << "Количество операций MethodSeidel: " << countoperation << endl;
	 return *newX;
 }

 Matrix& Matrix::MethodNewton(Matrix& R, const double eps)
 {
	 Matrix* newX;
	 Matrix lastX = R;

	 int countoperation = 0;

	 Matrix inv_J = (MethodYakobi(lastX.begin[0][0], lastX.begin[1][0], lastX.begin[2][0])).InverseGauss();
	 
	 Matrix f;
	 f.CreateNULL(3, 1);
	 f.begin[0][0] = F1(lastX[0], lastX[1], lastX[2]);
	 f.begin[1][0] = F2(lastX[0], lastX[1], lastX[2]);
	 f.begin[2][0] = F3(lastX[0], lastX[1], lastX[2]);
	 Matrix* mul;
	 //mul = &(inv_J*f);
	 mul=&(MatrixByVector(inv_J, f));
	 //cout << "mul:\n";
	 //mul->Show(10);
	 newX = &(lastX - f);

	 while (max(*newX, lastX) > eps) {
		 lastX = *newX;
		 f.begin[0][0] = F1(lastX[0], lastX[1], lastX[2]);
		 f.begin[1][0] = F2(lastX[0], lastX[1], lastX[2]);
		 f.begin[2][0] = F3(lastX[0], lastX[1], lastX[2]);
		 delete mul;
		 mul= &(MatrixByVector(inv_J, f));
		 delete newX;
		 newX = &(lastX - f);
		 countoperation++;
		 //cout << "Обратная матрица к Якоби на " << countoperation << " итерации:\n";
		 //nv_J.Show();
	 }
	 cout << "Количество операций MethodNewton: " << countoperation << endl;
	 return *newX;
 }

 Matrix& Matrix::Nevyazka3()
 {
	 Matrix* X = new Matrix();
	 X->CreateNULL(3, 1);

	 double x = (*this)[0];
	 double y = (*this)[1];
	 double z = (*this)[2];

	 X->begin[0][0] = F1(x, y, z);
	 X->begin[1][0] = F2(x, y, z);
	 X->begin[2][0] = F3(x, y, z);

	 return *X;
 }

 Matrix& Matrix::MatrixByVector(Matrix& G, Matrix& v)
 {
	 Matrix* result = new Matrix();
	 result->CreateNULL(G.n, 1);
	 double total = 0;
	 
	 for (size_t i = 0; i < G.n; i++)
	 {
		 for (size_t j = 0; j < v.n; j++)
		 {
			 total += G.begin[i][j] * v.begin[j][0];
		 }
		 result->begin[i][0]=total;
	 }
	 return *result;
 }

 Matrix& Matrix::Pkn(int k, int N, int t)
 {
	 N--;
	 Matrix* ns = new Matrix();
	 ns->CreateOnes(N+1, 1);
	 for (size_t i = 1; i <= N; i++)
	 {
		 ns->begin[i][0] = ns->begin[i - 1][0] * (N - i + 1);
	 }

	 Matrix* ts = new Matrix();
	 ts->CreateOnes(k + 1, 1);
	 for (size_t i = 1; i <= k; i++)
	 {
		 ts->begin[i][0] = ts->begin[i - 1][0] * (t - i + 1);
	 }

	 double dl = (2 * k + 1) * ns->begin[k][0];
	 double num = 1;
	 double stp = (N + k + 1);
	 
	 while (stp > N) {
		 num *= stp;
		 stp--;
	 }
	 double k_norm = sqrt(num / dl);

	 Matrix* p = new Matrix();
	 p->CreateNULL(k + 1, 1);
	 int s = 0;

	 double p_is;

	 for (size_t s = 0; s <= k; s++)
	 {
		 p->begin[s][0] = pow(-1, s) * C(s, k) * C(s, k + s) / ns->begin[s][0];
	 }
	 /*
	 double sum = 0,pr=1;
	 for (size_t k = 0; k < n; k++)
	 {
		 for (size_t s = 0; s <= n; s++)
		 {
			 P->begin[k][0] += pow(-1, s) * C(s, k) * C(s, k + s) * ts(t, s) * ts(n, s);
		 }
		 //cout<<k<<"] " << P->begin[k][0] << endl;
	 }*/
	 for (size_t i = 0; i < k+1; i++)
	 {
		 p->begin[i][0] = p->begin[i][0] * ts->begin[i][0];
	 }
	 return (*p);
 }

 Matrix& Matrix::Solve_coef(Matrix& X, int N, int m) // Вычисление коэф Фурье
 {
	 N--;
	 Matrix* P = new Matrix();
	 P->CreateNULL(m + 1, 1);
	 Matrix* A;

	 for (size_t i = 0; i < m+1; i++)
	 {
		 for (size_t j = 0; j < N+1; j++)
		 {
			 A=&(Pkn(i, N + 1, j));
			 P->begin[i][0] = X.begin[j][0]*A->sum();
			 delete A;
		 }
	 }
	 P->begin[0][0] = X.sum() / (N + 1);
	 return *P;
 }

 Matrix& Matrix::MethodRitz()
 {
	 Matrix *FM = new Matrix(*this);
	 CreateNULL(nR, nR);
	 FM->CreateNULL(nR,1);
	 for (int i = 0; i < n; i++)
	 {
		 for (int j = 0; j < m; j++)
		 {
			 this->begin[i][j] = compulationAij(i, j);
		 }
		 FM->begin[i][0] = compulationBj(i);
	 }
	 
	 return *FM;
 }

 Matrix& Matrix::ValuesInPoints(int n)
 {
	 Matrix* temp=new Matrix(*this);
	 temp->CreateNULL(n,1);
	 double unx = 0;
	 double durX = a;
	 for (int i = 0; i < n; i++) {
		 unx = phi0(durX);
		 for (int j = 0; j < this->n; j++)
		 {
			 unx += c[j] * phiK(durX, j + 1);
		 }
		 temp->begin[i][0] = unx;
		 durX += dl;
	 }
	 return *temp;
 }

 int Matrix::GetN()
 {
	 return n;
 }

 int Matrix::GetM()
 {
	 return m;
 }

 double Matrix::C(int k, int n)
 {
	 if (k > n) throw "!k<=n!";
	 if (n == 0) return 0;
	 if (k == 0 || k == n) return 1;
	 if (k == 1 || k==n-1) return n;
	 double ot = 1;
	 for (size_t i = k+1; i <= n; i++)
	 {
		 ot *= i;
	 }
	 for (size_t i = 1; i <= n-k; i++)
	 {
		 ot /= i;
	 }
	 return ot;
 }

 double Matrix::ts(int t, int s)
 {
	 double ot = 1;
	 for (size_t i = t-s+1; i <= t; i++)
	 {
		 ot *= i;
	 }
	 return ot;
 }

 double Matrix::operator[](int n)
 {
	 if (m < 1) throw "m<1";
	 return begin[n][0];
 }

 double Matrix::F1_S(double x, double y, double z)
 {
	 return 0.1-pow(x,2) + 2*y*z;
 }

 double Matrix::F2_S(double x, double y, double z)
 {
	 return -0.2 + pow(y,2) -3*x*z;
 }

 double Matrix::F3_S(double x, double y, double z)
 {
	 return 0.3 - pow(z,2) - 2*x*y;
 }

 double Matrix::F1(double x, double y, double z)
 {
	 return x + pow(x,2)-2*y*z-0.1;
 }

 double Matrix::F2(double x, double y, double z)
 {
	 return y - pow(y, 2) + 3 * x * z + 0.2;
 }

 double Matrix::F3(double x, double y, double z)
 {
	 return z + pow(z, 2) + 2 * x * y - 0.3;
 }

 double Matrix::max(double a, double b) {
	 return (a >= b) ? (a) : (b);
 }

 double Matrix::sum(void)
 {
	 double sum = 0;
	 for (size_t i = 0; i < n; i++)
	 {
		 for (size_t j = 0; j < m; j++)
		 {
			 sum += begin[i][j];
		 }
	 }
	 return sum;
 }

 double Matrix::max(Matrix&A,Matrix&B)
 {
	 double x = abs(A.begin[0][0] - B.begin[0][0]);
	 for (size_t i = 0; i < A.n; i++)
	 {
		 x = max(x, abs(A.begin[i][0] - B.begin[i][0]));
	 }
	 return x;
 }

 double Matrix::Norma(void)
 {
	 double norm = 0;
	 double sum = 0;
	 for (size_t i = 0; i < n; i++)
	 {
		 sum = 0;
		 for (size_t j = 0; j < m; j++)
		 {
			 sum += abs(begin[i][j]);
		 }
		 if (norm < sum)
			 norm = sum;
	 }
	 return norm;
 }

 double Matrix::NormaVector(int x)
 {
	 double sum = 0;
	 switch (x) {
	 case 1:
		 for (size_t i = 0; i < n; i++)
		 {
			 sum += abs(begin[i][0]);
		 }
		 break;
	 case 2:
		 for (size_t i = 0; i < n; i++)
		 {
			 sum += pow(begin[i][0], 2);
		 }
		 sum = sqrt(sum);
		 break;
	 default:
		 sum = abs(begin[0][0]);
		 for (size_t i = 0; i < n; i++)
		 {
			 if (abs(begin[i][0]) > sum)
				 sum = abs(begin[i][0]);
		 }
		 break;
	 }
	 return sum;
 }
	 

 void Matrix::append(double x)
 {
	 if (m != 1)throw"no vector";
	 // Пересоздаем и добавляем
	 double** temp = new double* [n + 1];
	 for (size_t i = 0; i < n; i++)
	 {
		 temp[i] = new double[1];
		 temp[i] = begin[i];
	 }
	 temp[n][0] = x;
	 
	 //Очистка begin
	 for (size_t i = 0; i < n; i++)
	 {
		 delete begin[i];
	 }
	 delete begin;
	 begin = temp;
	 n++;
 }

 double Matrix::kx(double x, int N)
 {
	 return (4.0 - 0.1 * x) / (pow(x, 2) + N / 16.0);
 }

 double Matrix::qx(double x, int N)
 {
	 return (x + 5.0) / (pow(x, 2) + 0.9 * N);
 }

 double Matrix::fx(double x, int N)
 {
	 return (N + x) / 3.5;
 }

 double Matrix::phi0(double x)
 {
	 return mu1 + (mu2 - mu1) * cos(PI / 2.0 + PI * (x - a) / (2.0 * (b - a)));
 }

 double Matrix::derPhi0(double x)
 {
	 return (mu2 - mu1) * PI / (2.0 * (b - a)) * sin((PI * (x - a) / (2.0 * (b - a))));
 }

 double Matrix::phiK(double x, int k)
 {
	 return -(pow((b - x), (k + 1)) * (b - 2 * a + x - a * k + k * x)) / (pow(k, 2) + 3 * k + 2);
 }

 double Matrix::derPhiK(double x, int k)
 {
	 return pow(b - x, k) * (x - a);
 }

 double Matrix::thetaA(double x, int i, int j)
 {
	 return kx(x, N) * derPhiK(x, i) * derPhiK(x, j) + qx(x, N) * phiK(x, i) * phiK(x, j);
 }

 double Matrix::thetaB(double x, int i, int j)
 {
	 return fx(x, N) * phiK(x, i) - qx(x, N) * phi0(x) * phiK(x, i) - kx(x, N) * derPhiK(x, i) * derPhi0(x);
 }

Matrix& Matrix::operator+(Matrix& temp) {
	if (this->n != temp.n) {
		cout << "n != temp.n" << endl;
	}
	if (this->m != temp.m) {
		cout << "m != temp.m" << endl;
	}

	Matrix *A=new Matrix(*this);
	for (int i = 0; i < A->n; i++)
	{
		for (int j = 0; j < A->m; j++) {
			A->begin[i][j] += temp.begin[i][j];
		}
	}
	return *A;
}

Matrix& Matrix::operator+(double ws)
{
	Matrix* X = new Matrix(*this);
	if (begin == nullptr) throw "Matrix is none";
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			X->begin[i][j] += ws;
		}
	}
	return *X;
}

Matrix& Matrix::operator-(Matrix& temp) {
	if (this->n != temp.n) {
		cout << "n != temp.n" << endl;
	}
	if (this->m != temp.m) {
		cout << "m != temp.m" << endl;
	}

	Matrix *A=new Matrix(*this);
	for (int i = 0; i < A->n; i++)
	{
		for (int j = 0; j < A->m; j++) {
			A->begin[i][j] -= temp.begin[i][j];
		}
	}
	return *A;
}

Matrix& Matrix::operator-(double ws)
{
	Matrix* X = new Matrix(*this);
	if (begin == nullptr) throw "Matrix is none";
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			X->begin[i][j] -= ws;
		}
	}
	return *X;
}

Matrix& Matrix::operator=(Matrix& temp) {
	Matrix A(temp);
	if (begin != nullptr) {
		for (size_t i = 0; i < n; i++)
		{
			delete begin[i];
		}
		delete begin;
	}
	n = A.n;
	m = A.m;
	begin = new double* [n];
	for (size_t i = 0; i < n; i++)
	{
		begin[i] = new double[m];
		for (size_t j = 0; j < m; j++)
		{
			begin[i][j] = A.begin[i][j];
		}
	}

	this->N = temp.N;
	this->nR = temp.n;
	this->a = temp.a;
	this->b = temp.b;
	this->dl = temp.dl;
	this->mu1 = temp.mu1;
	this->mu2 = temp.mu2;
	this->eps = temp.eps;

	for (unsigned short i = 0; i < 4; i++)
	{
		this->c[i] = temp.c[i];
		this->t[i] = temp.t[i];
	}

	return *this;
}

void Matrix::ReadFile(char* S) {
	if (S[1] == '\0') {
		cout << "Вы не указали путь к файлу, возьмем A.txt" << endl;
		S = (char*)"A.txt";
	}
	ifstream f;
	f.open(S);

	f >> n;
	f >> m;

	if (n < 1 || m < 1) {
		throw "n < 1 or m < 1";
	}

	//cout << n << " " << m << endl;

	double** begin = new double* [n];
	for (size_t i = 0; i < n; i++)
	{
		begin[i] = new double[m];
		for (size_t j = 0; j < m; j++)
		{
			f >> begin[i][j];
			//cout << "[" << begin[i][j] << "] ";
		}
		//cout << endl;
	}


	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++)
		{
			//cout << "[" << begin[i][j] << "] ";
		}
		//cout << endl;
	}

	f.close();
	this->begin = begin;
}

void Matrix::SetABDMM(int N, int nR, double c[4], double t[4], double eps)
{
	this->N = N;
	this->nR = nR;
	this->a = 0.6 - 3.0 / this->N;
	this->b = 2.0 - this->N / 13.0;
	this->dl=(b - a) / 5.0;
	this->mu1 = 15.0 / (this->N + 3.0);
	this->mu2 = -6.0*this->N/21.0;
	this->eps = eps;

	for (unsigned short i = 0; i < 4; i++)
	{
		this->c[i] = c[i];
		this->t[i] = t[i];
	}
}

Matrix& Matrix::Transp(void)
{
	double** newbegin = new double* [m];
	
	for (int i = 0; i < m; i++) {
		newbegin[i] = new double[n];
		for (int j = 0; j < n; j++) {
			newbegin[i][j] = begin[j][i];
		}
	}

	for (int i = 0; i < n; i++)
		delete begin[i];
	delete begin;

	begin = newbegin;
	return *this;
}
