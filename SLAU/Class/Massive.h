#pragma once

class Massive
{
	float **begin;
	int n, m;
public:
	Massive();
	Massive(int, int);
	Massive(const Massive&);
	Massive(float**, int, int);
	~Massive();
	void Create(int, int); // �������� ������� ������ ������
	void Create(); // ����� �������� ������ �� �����
	void CreateNULL(int, int); // �������� �������
	void Show();
	void ReadFile(char*);
	Massive& operator+(Massive& temp);
	Massive& operator-(Massive& temp);
	Massive& operator=(Massive& temp);
	Massive& operator*(Massive& temp);
};

