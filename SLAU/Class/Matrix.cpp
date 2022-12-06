#include "Matrix.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

 Matrix::Matrix() {
	begin = nullptr;
	n = 0;
	m = 0;
	permut = 0;
	det = 1;
}

 Matrix::Matrix(int n,int m) {
	 begin = nullptr;
	 n = 0;
	 m = 0;
	 permut = 0;
	 det = 1;

	 Create(n, m);
 }


Matrix::Matrix(const Matrix& temp) {
	this->n = temp.n;
	this->m = temp.m;
	this->det = temp.det;
	this->permut = temp.permut;
	this->begin = new float * [this->n];

	for (int i = 0; i < this->n; i++) {
		this->begin[i] = new float [this->m] ;
		for (int j = 0; j < this->m; j++) {
			this->begin[i][j] = temp.begin[i][j];
		}
	}
}

Matrix::Matrix(float** temp, int n, int m)
{
	this->n = n;
	this->m = m;
	this->det = 0;
	this->permut = 0;


	begin = new float* [n];
	for (size_t i = 0; i < n; i++)
	{
		begin[i] = new float[m];

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

float Matrix::GetDet()
{
	return det;
}

void Matrix :: Create() {
	cout << "1) ��������� ������ ������\n\n2) ������ �� �����\n������ �������� - ������ �� file.txt\n>> ";
	int x;
	char a[100];

	cin >> x;

	switch (x) {
	case(1):
		cout << "������� ����������� �������/\n";
		cout << "n: "; cin >> n;
		cout << "m: "; cin >> m;
		Create(n, m);
	case(2):
		cout << "������� ���� � �����.\n���� ������ ����� ���: int n int m float[n][m]\n������ ����� 2 ����� �����, � ����� �������. ���� << ";
		cin>>a;
		ReadFile(a);
		break;
	default:
		cout << "�� ������ �� ������ �� �������, ������� �������� �� ����� A.txt, ������ ����� � ���������� ���������.\n";
		ReadFile((char*)"A.txt");
		break;
	}
}

void Matrix::Create(char* S) {
	ReadFile(S);
}

 void Matrix::Create(int n, int m) {
	//cout << "���������� �������\n";
	if (n < 1 || m < 1)
		throw "n|m < 1";
	this->n = n;
	this->m = m;
	if(begin == nullptr)
		begin = new float* [n];
	
	cout << "1) ��������� ������\n2) ��������� ��������� �������\n>> ";
	int x;
	cin >> x;

	switch (x) {
	case(1):
		for (int i = 0; i < n; i++)
		{
			begin[i] = new float[m];
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
			begin[i] = new float[m];
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
		cout << "�� ������ �� ������ �� �������, ������� �������� ��������� �������.\n";

		for (int i = 0; i < n; i++)
		{
			begin[i] = new float[m];
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
	//cout << "���������� �������\n";
	if (n < 1 || m < 1)
		throw "n|m < 1";
	this->n = n;
	this->m = m;
	if (begin == nullptr)
		begin = new float* [n];
	for (int i = 0; i < n; i++)
	{
		begin[i] = new float[m];
		for (int j = 0; j < m; j++)
		{
			begin[i][j]=0;
		}
	}
}
 
 void Matrix::CreateDiagonal(int n) {
	//cout << "���������� �������\n";
	if (n < 1)
		throw "n< 1";
	this->n = n;
	this->m = n;
	if (begin == nullptr)
		begin = new float* [n];
	for (int i = 0; i < n; i++)
	{
		begin[i] = new float[m];
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

void Matrix::Show(int x) {
	//cout << "����� �������\n";
	cout << fixed;
	cout.precision(x);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "[" << begin[i][j] << "]\t";
		}
		cout << endl;
	}
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
	 // TODO: �������� ����� �������� return
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
	 // ������� ������� ����
	 float a12 = 0;

	 for (int i = 0; i < n-1; ++i) {
		 // ������������� �������� ��������. ���������� �� ��������� � ������� � � ��������� [0][0]
		 double MaxEl = temp.begin[i][i];
		 int iMaxEl = i;

		 // ����� ������� �������� ��������
		 for (int j = 0; j < n-i; ++j) {
			 // ���� ��������� ������� � ������ �� ������ ������, ��� ������� ������� �������, �� ��������� ���
			 if (abs(MaxEl) < abs(temp.begin[j+i][i])) {
				 MaxEl = temp.begin[j+i][i];
				 iMaxEl = j+i;
			 }
		 }
		 // ������ 1 ������ �� ������ � ������� ��������� � ����� ��������
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

		 // ����� ������ �� ������� �������
		 // ���������, �� �������� �� 2 ������� ��������
		 
		 right.begin[i][0] /= temp.begin[i][i];
		 
		 for (size_t j = i; j < n; j++)
		 {
			 temp.begin[i][j] /= temp.begin[i][i];
		 }

		 // �������� � ������-�������� ������� ������� A
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

	 // ���������� ������� 'x' ������� �������� �������������� ��������� Ax=f
	 //for (int i = n - 1; i >= 0; --i) {
		// float coeff_multiply = 0.0;
		// for (int j = i; j < n; ++j) {
		//	 coeff_multiply += temp.begin[i][j] * X->begin[j][0];
		//	 X->begin[i][0] = (right.begin[i][0] - coeff_multiply) / temp.begin[i][i];
		// }
	 //}

	 ////                    ***** 3 ������� *****
	 //// ������� 3. ���������� ������������ ������� ������� ������
	 //double value_det = temp.begin[0][0];
	 //// ��� ��� ������� � ��� �����������������, ����� ��������������.
	 //// �� ������������ ����� ������������ ���� ������������ ��������� �������, � ������ ������������
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

	 int* ite = new int[n]; // ����� ����� ����� ������� �����, �������� x2+x5+x1 ...

	 for (size_t i = 0; i < n; i++)
	 {
		 ite[i] = i;
	 }
	 
	 Matrix right = rightTemp; // ������ ������� - b
	 Matrix temp(*this); // ����� ������� - A
	 // ������� ������� ����
	 Matrix* X = new Matrix(); // ������� - x
	 X->CreateNULL(n, 1); // ������� �� n �����
	 float a12 = 0; // ��� ��������� ������� 2-� �����
	 double MainEl; // ������� ������� � ������
	 int iMainEl; // ������ �������� ��������


	 for (int i = 0; i < n; ++i) {
		 // ������������� �������� ��������. ���������� �� ��������� � ������� � �� ������� ���������
		 MainEl = temp.begin[i][i];
		 iMainEl = i;

		 // ����� ������� �������� ��������
		 for (int j = i; j < n; ++j) {
			 // ���� ��������� ������� � ������ �� ������ ������, ��� ������� ������� �������, �� ��������� ���
			 if (abs(MainEl) < abs(temp.begin[i][j])) {
				 MainEl = temp.begin[i][j];
				 iMainEl = j;
			 }
		 }
		 // ���� ������� ������� ����� �� ������� ���������, �� ������ �� ������ �������, � ����� ������ �������� ������� ������
		 if (iMainEl != i) {
			 // ����������� ���������� ������������
			 permut++;
			 // ������ ������� ������� � �������
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

		 // ������������ ��������������. ������ ��� ������ ������
		 for (int k = i + 1; k < n; ++k) {
			 double coeff_multiply = -(temp.begin[k][i] / temp.begin[i][i]);
			 right.begin[k][0] += coeff_multiply * right.begin[i][0];
			 for (int j = 0; j < n; ++j) {
				 temp.begin[k][j] += coeff_multiply * temp.begin[i][j];
			 }
		 }
	 }

	 // ���������� ������� 'x' ������� �������� �������������� ��������� Ax=f
	 for (int i = n - 1; i >= 0; --i) {
		 float coeff_multiply = 0.0;
		 for (int j = i; j < n; ++j) {
			 coeff_multiply += temp.begin[i][j] * X->begin[j][0];
		 }
		 X->begin[i][0] = (right.begin[i][0] - coeff_multiply) / temp.begin[i][i];
	 }
	 /*a12=X->begin[1][0];
	 X->begin[1][0]= X->begin[2][0];
	 X->begin[2][0] = a12;*/

	 // ������� 3. ���������� ������������ ������� ������� ������
	 double value_det = temp.begin[0][0];
	 // ��� ��� ������� � ��� �����������������, ����� ��������������.
	 // �� ������������ ����� ������������ ���� ������������ ��������� �������, � ������ ������������
	 
	 int a13 = 0;
	 
	 // �� ������ ������� x1,x2 ..., ������ ������ �������
	 bool bl1 = false;
	 while (true) { // ���������� 'x1','x2',.. �� ���� ����� (x4,x3,x1,x2 -> x1x2x3x4)
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

	 float** A1 = nullptr;

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
		 
		 A1 = new float* [temp.n];
		 for (size_t i = 0; i < n; i++)
		 {
			 A1[i] = new float[1];
			 A1[i][0] = temp.begin[i1][i];
		 }
		 R = new Matrix(A1, n, 1);
		 X=MethodGauss_bycolumn(*R); // ���������� i1-� �������
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
		 L.begin[i][i] = A.begin[i][i]; // ���� a[i][i]

		 for (size_t j = 0; j < i; j++)
		 {
			 L.begin[i][i] -= pow(L.begin[i][j], 2); // ������� �������� ����� �� l[i][i]
		 }

		 L.begin[i][i] = sqrt(L.begin[i][i]); // ���� ��� ������

		 for (size_t j = i + 1; j < n; j++) // ����� ����
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

 Matrix& Matrix::MethodYakobi(Matrix& F, Matrix& x, const float eps)
 {
	 Matrix TempX;
	 TempX.CreateNULL(n, 1);
	 Matrix* y = new Matrix(x);
	 float sum = 0;
	 float norm = 0;
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
			  norm = fabs(y->Norma2Vector() - TempX.Norma2Vector());

		  if (norm > fabs(y->Norma2Vector() - TempX.Norma2Vector()))
			  norm = fabs(y->Norma2Vector() - TempX.Norma2Vector());

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
	 // TODO: �������� ����� �������� return
 }

 Matrix& Matrix::MethodKVKor(Matrix& right)
 {
	 Matrix A = *this;
	 if (*this != A.Transp()) {
		 cout << "MethodKVKornya: Transp '!='\n";
		 return *this;
	 }
	 Matrix LT;
	 LT.CreateNULL(n, m);
	 Matrix L;
	 Matrix b = right;
	 Matrix y;
	 y.CreateNULL(b.n, b.m);
	 Matrix* x;
	 x = new Matrix(y);

	 for (size_t i = 0; i < n; i++)
	 {
		 LT.begin[i][i] = A.begin[i][i]; // ���� a[i][i]

		 for (size_t j = 0; j < i; j++)
		 {
			 LT.begin[i][i] -= pow(LT.begin[i][j], 2); // ������� �������� ����� �� l[i][i]
		 }

		 LT.begin[i][i] = sqrt(LT.begin[i][i]); // ���� ��� ������

		 for (size_t j = i + 1; j < n; j++) // ����� ����
		 {
			 LT.begin[j][i] = A.begin[j][i];

			 for (size_t ij = 0; ij < i; ij++)
			 {
				 LT.begin[j][i] -= LT.begin[j][ij] * LT.begin[i][ij];
			 }
			 LT.begin[j][i] /= LT.begin[i][i];
		 }
	 }

	 for (size_t i = 0; i < LT.n; i++)
	 {
		 y.begin[i][0] = b.begin[i][0];
		 for (size_t j = 0; j < i; j++)
		 {
			 y.begin[i][0] -= (LT.begin[i][j] * y.begin[j][0]);
		 }
		 y.begin[i][0] /= LT.begin[i][i];
	 }

	 L = LT;
	 L.Transp();

	 for (int i = L.n - 1; i >= 0; i--)
	 {
		 x->begin[i][0] = y.begin[i][0];
		 for (size_t j = L.m - 1; j > i; j--)
		 {
			 x->begin[i][0] -= (L.begin[i][j] * x->begin[j][0]);
		 }
		 x->begin[i][0] /= L.begin[i][i];
	 }

	 /*cout << "x: " << endl;
	 x->Show();
	 cout << "x Gauss: " << endl;
	 (LT.MethodGauss_bycolumn(L.MethodGauss_bycolumn(b))).Show();*/

	 return *x;
 }

 Matrix& Matrix::Integer(void)
 {
	 Matrix* X = new Matrix(*this);
	 for (size_t i = 0; i < n; i++)
	 {
		 X->begin[i][0] = (int)(X->begin[i][0]);
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

 float Matrix::Norma(void)
 {
	 float norm = 0;
	 float sum = 0;
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

 float Matrix::Norma2Vector(void)
 {
	 float sum = 0;
	 for (size_t i = 0; i < n; i++)
	 {
		 sum += pow(begin[i][0],2);
	 }
	 sum = sqrt(sum);
	 return sum;
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

Matrix& Matrix::operator+(float ws)
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

Matrix& Matrix::operator-(float ws)
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
	for (int i = 0; i < n; i++)
		delete begin[i];
	delete begin;
	this->n = temp.n;
	this->m = temp.m;
	begin = new float*[n];
	for (int i = 0; i < n; i++) {
		begin[i] = new float[m];
		for (int j = 0; j < m; j++) {
			begin[i][j] = A.begin[i][j];
		}
	}
	return *this;
}

void Matrix::ReadFile(char* S) {
	if (S[1] == '\0') {
		cout << "�� �� ������� ���� � �����, ������� A.txt" << endl;
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

	float** begin = new float* [n];
	for (size_t i = 0; i < n; i++)
	{
		begin[i] = new float[m];
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

Matrix& Matrix::Transp(void)
{
	float** newbegin = new float* [m];
	
	for (int i = 0; i < m; i++) {
		newbegin[i] = new float[n];
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
