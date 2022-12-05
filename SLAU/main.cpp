#include <iostream>
#include "Class/Matrix.h"
#include <fstream>
#include <string>

using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	Matrix A;
	A.Create((char*)"A.txt");
	Matrix* AT=nullptr;
	cout << "A : " << endl;
	A.Show();
	Matrix f;
	f.Create((char*)"f.txt");
	cout << "f: " << endl;
	f.Show();
	//A.Show();
	//B.Show();

	/*try { // Метод квадратного корня
		Matrix X1 = A.MethodGauss_bycolumn(f);
		Matrix X2 = A.MethodKVKor(f);
		cout << "MethodGauss: " << endl;
		X1.Show();
		cout << "MethodKvKornya: " << endl;
		X2.Show();

		cout << "Nevyazka:" << endl;
		Matrix rMG = A * X2 - f;
		cout << "r :" << endl;
		rMG.Show(10);

		cout << "MethodYakobi: " << endl;
		cout << "int X: " << endl;
		X2 = X2.Okrugl();
		X2.Show(10);
		Matrix MY = A.MethodYakobi(f, X2, 0.000001);
		cout << "MY: " << endl;
		MY.Show(10);

		cout << "Nevyazka:" << endl;
		Matrix rMY = A * X2 - f;
		rMY.Show(10);

		AT = &(A.InverseGauss());

		cout << "AT: " << endl;
		AT->Show();

		cout << "Norma: \n";
		cout << fixed;
		cout.precision(5);
		cout << "A: " << A.Norma() << endl;
		cout << "AT: " << AT->Norma() << endl;
		cout << "M(A) = " << A.Norma() * AT->Norma() << endl;
	}
	catch (...) {
		cout << "Error" << endl;
	}*/

	/*try { // Метод Гаусса по столбцу
		// 1
		Matrix X = A.MethodGauss_bycolumn(f); // Ax=f
		cout << "X :" << endl;
		X.Show();

		// 2
		Matrix r = A * X - f;
		cout << "r :" << endl;
		r.Show(10);

		cout << fixed;
		cout.precision(6);
		cout <<endl<< "det: " << A.GetDet()<<endl;

		cout << "inverse: " << endl;
		Matrix A_ = A.InverseGauss();
		A_.Show();

		cout << "A*A^(-1) :"<<endl;
		(A * A_).Show(6);
	}
	catch (...) {
		cout << "Error" << endl;
	}*/

	try { // Метод Холецкого
		Matrix X1 = A.MethodGauss_bycolumn(f);
		Matrix X2 = A.MethodHoleckogo(f);
		cout << "MethodGauss: " << endl;
		X1.Show();
		cout << "MethodHoleckogo: " << endl;
		X2.Show();
		//cout << "MethodGauss =? MethodHoleckogo: " << (X1 == X2) << endl;
		
		cout << "Nevyazka:" << endl;
		Matrix rMG = A * X2 - f;
		cout << "r :" << endl;
		rMG.Show(10);

		//cout << "MethodYakobi: " << endl;
		//cout << "int X: " << endl;
		//X2 = X2.Okrugl();
		//X2.Show(10);
		X2 = X2 + 1;
		Matrix MY = A.MethodYakobi(f, X2, 0.000001);
		cout << "Method Yakobi: " << endl;
		MY.Show(10);

		cout << "MethodGauss =? MethodHoleckogo: " << (MY == X2) << endl;

		cout << "Nevyazka:" << endl;
		Matrix rMY = A * MY - f;
		rMY.Show(10);

		AT = &(A.InverseGauss());

		cout << "AT: " << endl;
		AT->Show();

		cout << "Norma: \n";
		cout << fixed;
		cout.precision(5);
		cout<<"A: "<< A.Norma() << endl;
		cout <<"AT: "<< AT->Norma() << endl;
		//cout << "Norma =? 0: " << (0.0==(AT->GetNorm())) << endl;
		cout << "M(A) = " << A.Norma() * AT->Norma() << endl;
		//cout << "Norma: " << A.Norma() << endl;

	}
	catch (...) {
		cout << "Error" << endl;
	}

}

