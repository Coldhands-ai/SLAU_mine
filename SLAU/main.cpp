#include <iostream>
#include "Class/Matrix.h"
#include <fstream>
#include <string>

using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	Matrix A;
	//A.Create((char*)"A.txt");
	//Matrix* AT=nullptr;
	//cout << "A : " << endl;
	//A.Show();
	//f.Create((char*)"f.txt");
	//cout << "f: " << endl;
	//f.Show();
	//A.Show();
	//B.Show();

	try {
		const int N = 14;
		const int n = 4;
		double eps = 0.000001;
		double c[4] = { 0.34785484, 0.65214516, 0.65214516, 0.34785484 };
		double t[4] = { -0.86113631, -0.33998104, 0.33998104, 0.86113631 };
		A.SetABDMM(N, n, c,t, eps); // Передаются значения по умолчанию
		//A.MethodRitz();
		Matrix *f = &(A.MethodRitz());
		cout << "Число обусловленности: " << A.Norma() * (*&A.InverseGauss()).Norma()<<endl;
		cout << "A: \n";
		A.Show();
		//A.CreateNULL(n, n);
		//A.ShowAll(2);
		cout << "b: \n";
		f->Show(2);

		Matrix* X = &(A.MethodGauss_bycolumn(*f));
		cout << "x:\n";
		X->Show();

		Matrix* Nev;

		cout << "Невязка: \n";
		Nev = &(A * (*X) - (*f));
		Nev->Show(20);

		cout << "Значения в точках: \n";
		Matrix* ZinT = &(A.ValuesInPoints(6));
		ZinT->Show();
	}
	catch (...) {
		cout << "Error" << endl;
	}


	/*try { 

		cout << "Method Seidel: " << endl;
		Matrix* X1 = &(A.MethodSeidel(f,0.001));
		X1->Show(4);

		cout << "Nevyazka: " << endl;
		Matrix* NX1 = &(X1->Nevyazka3());
		NX1->Show(6);

		cout << "Method Newton: " << endl;
		Matrix* X2 = &(A.MethodNewton(*X1, 0.000001));
		X2->Show(4);

		cout << "Nevyazka: " << endl;
		Matrix* NX2 = &(X2->Nevyazka3());
		NX2->Show(10);
	}
	catch (...) {
		cout << "Error" << endl;
	}*/

	/*try {
		const int m = 3;
		const int n = 2;
		cout << "Method : " << endl;
		Matrix* X = new Matrix();
		X->CreatePoly('x',n);
		Matrix* Y = new Matrix();
		Y->CreatePoly('y',n);
		cout << "X: " << endl;
		cout << "Y: " << endl;
		Y->Show(*X);
		Matrix* Q=&(Y->Solve_coef(*X,X->GetN(), m));
		cout << "Q(t) = ";
		for (size_t i = 0; i < m; i++)
		{
			cout << (*Q)[i] << "+P("<< i <<","<< X->GetN() <<") ";
		}
	}
	catch (...) {
		cout << "Error" << endl;
	}*/
	
	return 0;
}

