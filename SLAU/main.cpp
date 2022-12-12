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

		cout << "Method Seidel: " << endl;
		Matrix* X1 = &(A.MethodSeidel(f,0.001));
		X1->Show(4);

		cout << "Nevyazka: " << endl;
		Matrix* NX1 = &(X1->Nevyazka3());
		NX1->Show(6);

		cout << "Method Newton: " << endl;
		Matrix* X2 = &(A.MethodNewton(*X1, 0.00001));
		X2->Show(4);

		cout << "Nevyazka: " << endl;
		Matrix* NX2 = &(X2->Nevyazka3());
		NX2->Show(6);
	}
	catch (...) {
		cout << "Error" << endl;
	}

}

