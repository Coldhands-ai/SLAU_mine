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

	try {

		cout << "Method KVKornya: " << endl;
		Matrix* X1 = &(A.MethodKVKor(f));
		X1->Show(4);

		cout << "Nevyazka: " << endl;
		Matrix* NX1 = &(A*(*X1)-f);
		NX1->Show(14);

		X1 = &(X1->Integer());
		cout << "int X1: \n";
		X1->Show(4);

		cout << "Method Zeydel: " << endl;
		Matrix* X2 = &(A.MethodGaussZeydel(f,*X1,0.000001));
		X2->Show(4);

		cout << "Nevyazka: " << endl;
		Matrix* NX2 = &(A * (*X2) - f);
		NX2->Show(14);
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

}

