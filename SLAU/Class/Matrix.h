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
	void Create(int, int); // �������� ������� ������ ������
	void Create(); // ����� �������� ������ �� �����
	void CreateNULL(int, int); // �������� �������
	void Show();
	void ReadFile(char*);
	Matrix& operator+(Matrix& temp);
	Matrix& operator-(Matrix& temp);
	Matrix& operator=(Matrix& temp);
	Matrix& operator*(Matrix& temp);

};

