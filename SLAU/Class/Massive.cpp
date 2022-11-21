#include "Massive.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

 Massive::Massive() {
	begin = nullptr;
	n = 0;
	m = 0;
}

 Massive::Massive(int n,int m) {
	 Create(n, m);
 }

 Massive::Massive(float** temp,int n, int m) {
	this->n = n;
	this->m = m;
	this->begin = new float * [this->n];

	for (int i = 0; i < n; i++) {
		this->begin[i] = new float[this->m];
		for (int j = 0; j < m; j++) {
			this->begin[i][j] = temp[i][j];
		}
	}
}

Massive::Massive(const Massive& temp) {
	this->n = temp.n;
	this->m = temp.m;

	this->begin = new float * [this->n];

	for (int i = 0; i < this->n; i++) {
		this->begin[i] = new float [this->m] ;
		for (int j = 0; j < this->m; j++) {
			this->begin[i][j] = temp.begin[i][j];
		}
	}
}

Massive::~Massive(void){
	if (begin != nullptr) {
		for (int i = 0; i < n; i++) {
			delete begin[i];
		}
		delete begin;
	}
}

void Massive :: Create() {
	cout << "1) ��������� ������ ������\n\n2) ������ �� �����\n������ �������� - ������ �� file.txt\n>>" << endl;
	int x;
	string a;

	cin >> x;

	switch (x) {
	case(1):
		cout << "������� ����������� �������/\n";
		cout << "n: "; cin >> n;
	case(2):
		cout << "������� ���� � �����.\n���� ������ ����� ���: int n int m float[n][m]\n������ ����� 2 ����� �����, � ����� �������. ���� << ";
		getline(cin,a);
		ReadFile((char*)&a);
		break;
	default:
		cout << "�� ������ �� ������ �� �������, ������� �������� �� ����� file.txt, ������ ����� � ���������� ���������.\n";
		ReadFile((char*)"file.txt");
		break;
	}
}

 void Massive::Create(int n, int m) {
	cout << "���������� �������\n";
	if (n < 1 || m < 1)
		throw "n|m < 1";
	this->n = n;
	this->m = m;
	if(begin == nullptr)
		begin = new float* [n];
	
	cout << "1) ��������� ������\n2) ��������� ��������� �������\n>>" << endl;
	int x;
	cin >> x;

	switch (x) {
	case(1):
		for (int i = 0; i < n; i++)
		{
			begin[i] = new float[m];
			for (int j = 0; j < m; j++)
			{
				cout << "[" << i << "][" << j << "] = ";
				cin >> begin[i][j];
				cout << endl;
			}
		}
		break;
	case(2):
		for (int i = 0; i < n; i++)
		{
			begin[i] = new float[m];
			for (int j = 0; j < m; j++)
			{
				//cout << "[" << i << "][" << j << "] = "; 
				begin[i][j]=rand()%1000/100.0;
				//cout << begin[i][j];
				//cout << endl;
			}
		}
		break;
	default:
		cout << "�� ������ �� ������ �� �������, ������� �������� ��������� �������.\n";

		for (int i = 0; i < n; i++)
		{
			begin[i] = new float[m];
			for (int j = 0; j < m; j++)
			{
				//cout << "[" << i << "][" << j << "] = "; 
				begin[i][j] = rand() % 1000 / 100.0;
				//cout << begin[i][j];
				//cout << endl;
			}
		}
		break;
	}
}

 void Massive::CreateNULL(int n, int m) {
	cout << "���������� �������\n";
	if (n < 1 || m < 1)
		throw "n|m < 1";
	this->n = n;
	this->m = m;
	if (begin == nullptr)
		begin = new float* [n];
	for (int i = 0; i < n; i++)
	{
		begin[i] = new float[m];
		for (int j = 0; j < m; j++)
		{
			begin[i][j]=0;
		}
	}
}


void Massive::Show() {
	cout << "����� �������\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "|" << begin[i][j] << "|";
		}
		cout << endl;
	}
}

 Massive& Massive::operator*(Massive& temp) {
	 cout << "[" << n << "][" << m << "] ? [" << temp.n << "][" << temp.m << "]" << endl;
	if (this->m != temp.n) {
		throw "m != temp.n";
	}
	Massive *A=new Massive();
	A->CreateNULL(n, temp.m);
	for (int i = 0; i < A->n; i++){
		for (int j = 0; j < A->m; j++) {
			for (int x = 0; x < m; x++)
			{
				A->begin[i][j] += begin[i][x] * temp.begin[x][j];
			}
		}
	}
	return *A;
}

Massive& Massive::operator+(Massive& temp) {
	if (this->n != temp.n) {
		cout << "n != temp.n" << endl;
	}
	if (this->m != temp.m) {
		cout << "m != temp.m" << endl;
	}

	Massive *A=new Massive(*this);
	for (int i = 0; i < A->n; i++)
	{
		for (int j = 0; j < A->m; j++) {
			A->begin[i][j] += temp.begin[i][j];
		}
	}
	return *A;
}

Massive& Massive::operator-(Massive& temp) {
	if (this->n != temp.n) {
		cout << "n != temp.n" << endl;
	}
	if (this->m != temp.m) {
		cout << "m != temp.m" << endl;
	}

	Massive *A=new Massive(*this);
	for (int i = 0; i < A->n; i++)
	{
		for (int j = 0; j < A->m; j++) {
			A->begin[i][j] -= temp.begin[i][j];
		}
	}
	return *A;
}

Massive& Massive::operator=(Massive& temp) {
	for (int i = 0; i < n; i++)
		delete begin[i];
	delete begin;
	this->n = temp.n;
	this->m = temp.m;
	begin = new float*[n];
	for (int i = 0; i < n; i++) {
		begin[i] = new float[m];
		for (int j = 0; j < m; j++) {
			begin[i][j] = temp.begin[i][j];
		}
	}
	return *this;
}

void Massive::ReadFile(char* S) {
	if (sizeof(S) == 0) {
		cout << "�� �� ������� ���� � �����, ������� file.txt" << endl;
		S = (char*)"file.txt";
	}
	ifstream f;
	f.open(S);

	f >> n;
	f >> m;

	if (n < 1 || m < 1) {
		throw "n < 1 or m < 1";
	}

	cout << n << " " << m << endl;

	float** begin = new float* [n];
	for (size_t i = 0; i < n; i++)
	{
		begin[i] = new float[m + 1];
		for (size_t j = 0; j < m; j++)
		{
			f >> begin[i][j];
			cout << "[" << begin[i][j] << "] ";
		}
		begin[i][m] = NULL;
		cout << endl;
	}
	begin[n] = new float[m + 1];
	for (int i = 0; i <= m; i++) {
		begin[n][i] = NULL;
	}

	f.close();
}