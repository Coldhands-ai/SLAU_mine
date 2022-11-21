#pragma once

class Matrix
{
	float **begin;
	int n, m;
	int permut;
	float det;
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	Matrix(float** temp, int, int);
	~Matrix();
	float GetDet();
	void Create(int, int); // создание массива внутри класса
	void Create(); // Можно вытащить массив из файла
	void CreateDiagonal(int); // Можно вытащить массив из файла
	void Create(char*); // Вытащить массив из файла
	void CreateNULL(int, int); // создание пустого
	void Show();
	void Show(int);
	void ReadFile(char*);
	Matrix& operator+(Matrix& temp);
	Matrix& operator-(Matrix& temp);
	Matrix& operator=(Matrix& temp);
	Matrix& operator*(Matrix& temp);
	Matrix& MethodGauss(Matrix& right);
	Matrix& InverseGauss();
};

