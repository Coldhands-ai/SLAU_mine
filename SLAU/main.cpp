#include <iostream>
#include "Class/Matrix.h"
#include <fstream>
#include <string>

using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	Matrix A;
	A.Create((char*)"A.txt");
	cout << "A : " << endl;
	A.Show();
	Matrix f;
	f.Create((char*)"f.txt");
	cout << "f: " << endl;
	f.Show();
	//A.Show();
	//B.Show();

	try {
		// 1
		Matrix X = A.MethodGauss(f);
		cout << "X :" << endl;
		X.Show();
		// 2
		Matrix r = A * X - f;
		cout << "r :" << endl;
		r.Show(10);

		cout << "det: " << A.GetDet();
		cout << "A :" << endl;
		A.Show();
	}
	/*catch (char* a) {
		cout << "Error: " << a << endl;
	}*/
	catch (...) {
		cout << "Error" << endl;
	}
}

