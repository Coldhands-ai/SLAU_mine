#pragma once

class Matrix
{
	float **begin;
	int n, m;
	int permut;
	float det;
	float norma;
	int countiterationnorm;
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	Matrix(float** temp, int, int);
	~Matrix();
	float GetDet();
	void Create(int, int); // �������� ������� ������ ������
	void Create(); // ����� �������� ������ �� �����
	void CreateDiagonal(int); // ����� �������� ������ �� �����
	void Create(char*); // �������� ������ �� �����
	void CreateNULL(int, int); // �������� �������
	void Show();
	void Show(int);
	void ReadFile(char*);
	Matrix& Transp(void);
	Matrix& operator+(Matrix& temp);
	Matrix& operator-(Matrix& temp);
	Matrix& operator=(Matrix& temp);
	Matrix& operator*(Matrix& temp);
	bool operator==(Matrix& temp);
	bool operator!=(Matrix& temp);
	//Matrix& MethodGauss_byrow(Matrix&);
	Matrix& MethodGauss_bycolumn(Matrix&);
	Matrix& InverseGauss();
	Matrix& MethodHoleckogo(Matrix&);
	Matrix& MethodYakobi(Matrix&, Matrix&,const float);
	Matrix& Integer(void);
	Matrix& Okrugl(void);
	int Norma(void);
	float GetNorm(void);
	int GetCountIterationNorm(void);
};

