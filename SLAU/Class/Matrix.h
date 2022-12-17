#pragma once

class Matrix
{
	double **begin;
	int n, m;
	int permut;
	double det;
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	Matrix(double** temp, int, int);
	~Matrix();
	double GetDet();
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
	Matrix& operator+(double);
	Matrix& operator-(Matrix&);
	Matrix& operator-(double);
	Matrix& operator=(Matrix&);
	Matrix& operator*(Matrix&);
	bool operator==(Matrix&);
	bool operator!=(Matrix&);
	//Matrix& MethodGauss_byrow(Matrix&);
	Matrix& MethodGauss_bycolumn(Matrix&);
	Matrix& InverseGauss();
	Matrix& MethodHoleckogo(Matrix&);
	Matrix& MethodYakobi(Matrix&, Matrix&,const double);
	Matrix& MethodKVKor(Matrix&);
	Matrix& MethodGaussZeydel(Matrix&, Matrix&, const double);
	Matrix& Integer(void);
	Matrix& Okrugl(void);
	Matrix& MethodYakobi(double, double, double);
	Matrix& MethodSeidel(Matrix&, const double);
	Matrix& MethodNewton(Matrix&, const double);
	Matrix& Nevyazka3();
	Matrix& MatrixByVector(Matrix&, Matrix&);
	double operator[](int);
	double F1_S(double,double,double);
	double F2_S(double,double,double);
	double F3_S(double,double,double);
	double F1(double,double,double);
	double F2(double,double,double);
	double F3(double,double,double);
	double max(Matrix&,Matrix&);
	double max(double,double);
	double Norma(void);
	double NormaVector(int);
	void append(double);
};

