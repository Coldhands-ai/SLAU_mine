#include <iostream>
#include "Class/Matrix.h"
#include <fstream>
#include <string>

using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	Matrix A;
	A.Create((char*)"A.txt");
	Matrix B;
	B.Create((char*)"f.txt");
	A.Show();
	B.Show();

	try {
		(B * A).Show();
	}
	/*catch (char* a) {
		cout << "Error: " << a << endl;
	}*/
	catch (...) {
		cout << "Error" << endl;
	}
}

