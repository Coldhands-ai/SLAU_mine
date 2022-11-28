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
		Matrix X = A.MethodGauss_byrow(f); // Ax=f
		cout << "X :" << endl;
		X.Show();

		cout << "Интернет :" << endl;
		cout<< 3986360802310915.0/1744944907835144.0 <<endl;
		cout<< 7157427694728137.0/4038301072418477.0 <<endl;
		cout<< -12686144454163276.0/8076602144836955.0 <<endl;
		cout<< 2295917291102105.0/10279311820701576.0 <<endl;
		cout<< -3327424259340216.0/4000441713451591.0 <<endl;
		cout<< -5842563673633112.0/5850392885900717.0 <<endl;

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
	/*catch (char* a) {
		cout << "Error: " << a << endl;
	}*/
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

