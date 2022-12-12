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
	Matrix& Transp(void);
	Matrix& operator+(Matrix&);
	Matrix& operator+(float);
	Matrix& operator-(Matrix&);
	Matrix& operator-(float);
	Matrix& operator=(Matrix&);
	Matrix& operator*(Matrix&);
	bool operator==(Matrix&);
	bool operator!=(Matrix&);
	//Matrix& MethodGauss_byrow(Matrix&);
	Matrix& MethodGauss_bycolumn(Matrix&);
	Matrix& InverseGauss();
	Matrix& MethodHoleckogo(Matrix&);
	Matrix& MethodYakobi(Matrix&, Matrix&,const float);
	Matrix& MethodKVKor(Matrix&);
	Matrix& MethodGaussZeydel(Matrix&, Matrix&, const float);
	Matrix& Integer(void);
	Matrix& Okrugl(void);
	Matrix& MethodYakobi(float, float, float);
	Matrix& MethodSeidel(Matrix&, const float);
	Matrix& MethodNewton(Matrix&, const float);
	Matrix& Nevyazka3();
	Matrix& MatrixByVector(Matrix&, Matrix&);
	float operator[](int);
	float F1_S(float,float,float);
	float F2_S(float,float,float);
	float F3_S(float,float,float);
	float F1(float,float,float);
	float F2(float,float,float);
	float F3(float,float,float);
	float max(Matrix&,Matrix&);
	float max(float,float);
	float Norma(void);
	float Norma2Vector(void);
	void append(float);
};

