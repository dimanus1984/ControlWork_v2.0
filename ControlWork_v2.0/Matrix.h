#pragma once
#include<iostream>
using namespace std;
template <class T>	// ��������� ����� �������.

class Matrix
{
	T** M;
	int m; // ���������� �����.
	int n; // ���������� ��������.

public:
	int get_M()const;
	int get_m()const;
	int get_n()const;
	void set_M(int i, int j, int value);
	void set_m(int m);
	void set_n(int n);

	//	Consctructors:
	Matrix();						// Default constructor.
	Matrix(int m, int n);			// Constructor with two parameters.
	Matrix(const Matrix& right);	// CopyConstructor.
	Matrix(Matrix&& right);			// MoveConstructor.
	~Matrix();

	//	 Operators:
	Matrix operator=(const Matrix& right);	// CopyAssignment.
	Matrix& operator=(Matrix&& right);		// MoveAssignment.
	Matrix operator+(const Matrix& right);
	Matrix operator-(const Matrix& right);
	Matrix& operator[](int i);	// ������������� �������� ������ �������.

	//	Methods:
	void Rand();
	void print();
};

template<typename T>
ostream& operator<<(ostream& os, Matrix<T>& obj)
{
	obj.print();
	return os;
}