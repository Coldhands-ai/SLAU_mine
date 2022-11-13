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
	void Create(int, int); // создание массива внутри класса
	void Create(); // ћожно вытащить массив из файла
	void CreateNULL(int, int); // создание пустого
	void Show();
	void ReadFile(char*);
	Massive& operator+(Massive& temp);
	Massive& operator-(Massive& temp);
	Massive& operator=(Massive& temp);
	Massive& operator*(Massive& temp);
};

