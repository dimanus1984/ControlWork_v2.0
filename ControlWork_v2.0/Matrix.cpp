#include "Matrix.h"

template<typename T>
inline int Matrix<T>::get_M() const
{
	return **M;
}

template<typename T>
inline int Matrix<T>::get_m() const
{
	return m;
}

template<typename T>
inline int Matrix<T>::get_n() const
{
	return n;
}

template<typename T>
inline void Matrix<T>::set_M(int i, int j, int value)
{
	this->M[i][j] = value;
}

template<typename T>
inline void Matrix<T>::set_m(int m)
{
	this->m = m;
}

template<typename T>
inline void Matrix<T>::set_n(int n)
{
	this->n = n;
}

template<typename T>
Matrix<T>::Matrix()	// Default constructor.
{
	m = n = 0;
	M = 0;
}

template<typename T>
Matrix<T>::Matrix(int m, int n)	// Constructor with two parameters.
{
	this->m = m;
	this->n = n;
	// 1) Создаем массив указателей:
	M = new T * [m];
	// 2) Выделяем память под строки двумерного массива:
	for (int i = 0; i < m; i++)
		M[i] = new T[n]{};
	// 3) Заполняем массив нулями:
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			M[i][j] = 0;
}

template<typename T>
Matrix<T>::Matrix(const Matrix& right)	// CopyConstructor.
{
	m = right.m;
	n = right.n;
	M = new T * [m];
	for (int i = 0; i < m; i++)
	{
		M[i] = new T[n]{};
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			M[i][j] = right.M[i][j];
		}
	}
}

template<typename T>
Matrix<T>::Matrix(Matrix&& right)	// MoveConstructor.
{
	this->M = right.M;
	this->m = right.m;
	this->n = right.m;
	right.M = nullptr;	//Указатель на ноль (NULL pointer) - указатель в никуда.
}

template<typename T>
Matrix<T>::~Matrix()
{
	delete[] M;
}

template<typename T>
Matrix<T> Matrix<T>::operator=(const Matrix& right)	// CopyAssignment.
{
	if (n > 0)
	{
		for (int i = 0; i < m; i++)	// освободить память, выделенную ранее для объекта *this
			delete[] M[i];
	}
	if (m > 0)
	{
		delete[] M;
	}
	m = right.m;
	n = right.n;
	M = new T * [m];
	for (int i = 0; i < m; i++)
	{
		M[i] = new T[n]{};
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			M[i][j] = right.M[i][j];
		}
	}
	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& right)	// MoveAssignment.
{
	if (this == &right)return *this;
	if (n > 0)
	{
		for (int i = 0; i < m; i++)	// освободить память, выделенную ранее для объекта *this
			delete[] M[i];
	}
	if (m > 0)
	{
		delete[] M;
	}
	this->M = right.M;
	this->m = right.m;
	this->n = right.n;
	right.M = nullptr;
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& right)
{
	Matrix result(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result.M[i][j] = M[i][j] + right.M[i][j];
		}
	}
	return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& right)
{
	Matrix result(m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result.M[i][j] = M[i][j] - right.M[i][j];
		}
	}
	return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator[](int i)
{
	return M[i];	// Возврат ссылки на элемент массива.
}

template<typename T>
void Matrix<T>::Rand()
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			M[i][j] = rand() % 10;
}

template<typename T>
void Matrix<T>::print()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << M[i][j] << "\t";
		}
		cout << endl;
	}
}