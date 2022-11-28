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
		cout << "MethodGauss =? MethodHoleckogo: " << (X1 == X2) << endl;

		cout << "Nevyazka:" << endl;
		Matrix r = A * X2 - f;
		cout << "r :" << endl;
		r.Show(10);
	}
	catch (...) {
		cout << "Error" << endl;
	}

	//try {
	//	// 1
	//	Matrix X = A.MethodGauss_bycolumn(f); // Ax=f
	//	cout << "X :" << endl;
	//	X.Show();

	//	// 2
	//	Matrix r = A * X - f;
	//	cout << "r :" << endl;
	//	r.Show(10);

	//	cout << fixed;
	//	cout.precision(6);
	//	cout << endl << "det: " << A.GetDet() << endl;

	//	cout << "inverse: " << endl;
	//	Matrix A_ = A.InverseGauss();
	//	A_.Show();

	//	cout << "A*A^(-1) :" << endl;
	//	(A * A_).Show(6);
	//}
	///*catch (char* a) {
	//	cout << "Error: " << a << endl;
	//}*/
	//catch (...) {
	//	cout << "Error" << endl;
	//}
}

