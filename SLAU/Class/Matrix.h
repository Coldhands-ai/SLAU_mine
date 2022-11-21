#pragma once

class Matrix
{
	float **begin;
	int n, m;
	int permut;
	int det;
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	Matrix(float* temp[], int, int);
	~Matrix();
	int GetDet();
	void Create(int, int); // �������� ������� ������ ������
	void Create(); // ����� �������� ������ �� �����
	void Create(char*); // �������� ������ �� �����
	void CreateNULL(int, int); // �������� �������
	void Show();
	void Show(int);
	void ReadFile(char*);
	Matrix& operator+(Matrix& temp);
	Matrix& operator-(Matrix& temp);
	Matrix& operator=(Matrix& temp);
	Matrix& operator*(Matrix& temp);
	Matrix& MethodGauss(Matrix& right);
};

