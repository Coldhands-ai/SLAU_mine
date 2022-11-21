#pragma once

class Matrix
{
	float **begin;
	int n, m;
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	Matrix(float* temp[], int, int);
	~Matrix();
	void Create(int, int); // создание массива внутри класса
	void Create(); // ћожно вытащить массив из файла
	void CreateNULL(int, int); // создание пустого
	void Show();
	void ReadFile(char*);
	Matrix& operator+(Matrix& temp);
	Matrix& operator-(Matrix& temp);
	Matrix& operator=(Matrix& temp);
	Matrix& operator*(Matrix& temp);

};

