#include <iostream>
#include "Class/Matrix.h"
#include <fstream>
#include <string>

using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	float Massive[1][4] = { {1.36, 1.56, 1.78, 1.91} };
	Matrix M1(Massive, 1, 4);
}

