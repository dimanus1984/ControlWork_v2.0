#include<iostream>
#include"Matrix.h"
#include"Matrix.cpp"
using namespace std;

#define delimiter "\n---------------------------------------------------------\n"

void main()
{
	setlocale(LC_ALL, "Russian");
	int m, n;
	cout << "¬ведите размер матрицы (количество строк и столбцов):" << endl;
	cin >> m >> n;
	cout << delimiter << endl;
	cout << "One Matrix" << endl;
	Matrix<int> M(m, n);
	M.Rand();
	M.print();
	//cout << delimiter << endl;
	//cout << M;  // ѕерегруженный оператор вывода.
	cout << delimiter << endl;
	cout << "Two Matrix" << endl;
	Matrix<int> M1(m, n);
	M1.Rand();
	M1.print();
	cout << delimiter << endl;
	cout << "Addition Two Matrix" << endl;
	Matrix<int> M2;
	M2 = M + M1;
	M2.print();
	cout << delimiter << endl;
	cout << "Brooding Two Matrix" << endl;
	M2 = M - M1;
	M2.print();
}