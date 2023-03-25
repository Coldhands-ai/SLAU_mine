#pragma once

class Matrix
{
	double **begin;
	int n, m;
	int permut;
	double det;
	int nR; // Размерность
	int N; // Вариант
	double PI;
	double c[4];
	double t[4];
	double a, b, dl, mu1, mu2;
	double eps = 0.000001;
	typedef double (Matrix::* function)(double, int, int);
	//using function = double(Matrix::*)(double, int, int);
	function f_ptr;
	//int N;

	double compulationAij(int, int);
	double compulationBj(int);
	double GaussIntegral(int i, int j, function, double, double);
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
	void CreateNULL(int, int); // создание Нулевое
	void CreateOnes(int, int); // создание Единичное
	void CreatePoly(char,int);
	void Show();
	void Show(Matrix&);
	void Show(int);
	void Show(Matrix&,int);
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
	Matrix& Pkn(int,int,int);
	Matrix& Solve_coef(Matrix&, int, int);
	int GetN();
	int GetM();
	double C(int, int);
	double ts(int,int);
	double operator[](int);
	double F1_S(double,double,double);
	double F2_S(double,double,double);
	double F3_S(double,double,double);
	double F1(double,double,double);
	double F2(double,double,double);
	double F3(double,double,double);
	double max(Matrix&,Matrix&);
	double max(double,double);
	double sum(void);
	double Norma(void);
	double NormaVector(int);
	void append(double);

	double kx(double, int);
	double qx(double, int);
	double fx(double, int);
	double phi0(double);
	double derPhi0(double);
	double phiK(double, int);
	double derPhiK(double, int);
	double thetaA(double, int, int);
	double thetaB(double, int, int);
};

