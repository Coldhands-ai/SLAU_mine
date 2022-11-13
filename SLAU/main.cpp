#include <iostream>
#include "Class/Massive.h"
#include <fstream>
#include <string>

using namespace std;

float** ReadFile(char* S) {
	ifstream f;
	f.open(S);
	if (!f.is_open()) {
		cout << "Файл не открыт / не найден\n";
		return nullptr;
	}

	int n, m;
	f >> n;
	f >> m;

	cout << n << " " << m << endl;

	float** matrix = new float*[n];
	for (size_t i = 0; i < n; i++)
	{
		matrix[i] = new float[m+1];
		for (size_t j = 0; j < m; j++)
		{
			f>>matrix[i][j];
			cout << "[" << matrix[i][j] << "] ";
		}
		matrix[i][m] = NULL;
		cout << endl;
	}
	matrix[n] = new float[m + 1];
	for (int i = 0; i <= m; i++) {
		matrix[n][i] = NULL;
	}

	f.close();
	return matrix;
}

int main() {
	setlocale(LC_ALL, "rus");
	cout << "S" << endl;/*
	char* a = new char[40];
	cin >> a;
	float** x = ReadFile(a);
	
	for (int i = 0; x[i][0]!=NULL; i++){
		cout << x[i][0]  << endl;
	}*/

	Massive A;
	A.Create();
	
}

