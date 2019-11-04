#include "Matrix.h"

Matrix::Matrix()
{
	size = 0;
}

Matrix::Matrix(int inSize)
{
	size = inSize;
	matrix = new int*[size];

	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
}

Matrix::Matrix(const Matrix &m)
{
	size = m.size;
	matrix = new int*[size];

	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = m.matrix[i][j];
		}
	}

}

Matrix::~Matrix()
{
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Matrix::printMatrix() {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int Matrix::getSize()
{
	return size;
}

void Matrix::operator =(const Matrix &m)const
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = m.matrix[i][j];
		}
	}
}

Matrix Matrix::operator +(Matrix &m)
{
	Matrix out(size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			out.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
		}
	}

	return out;
}

Matrix Matrix::operator -(Matrix &m)
{
	Matrix out(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			out.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
		}
	}

	return out;
}

Matrix Matrix::operator *(Matrix &m)
{
	Matrix out(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			out.matrix[i][j] = matrix[i][j] * m.matrix[i][j];
		}
	}

	return out;
}

Matrix& Matrix::operator ++()
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j]++;
		}
	}
	return *this;
}

Matrix& Matrix::operator --()
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j]--;
		}
	}
	return *this;
}

Matrix Matrix::operator ++(int)
{
	Matrix out = *this;
	++*this;
	return out;
}

Matrix Matrix::operator --(int)
{
	Matrix out = *this;
	--*this;
	return out;
}

Matrix Matrix::operator ~()
{
	Matrix out(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			out.matrix[i][j] = matrix[j][i];
		}
	}

	return out;
}

Matrix Matrix::operator ^(Matrix &m)
{
	Matrix out(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			out.matrix[i][j] = matrix[i][j]^matrix[i][j];
		}
	}

	return out;
}

std::ostream& operator <<(std::ostream& os, Matrix &m)
{
	for (int i = 0; i < m.size; i++) {
		for (int j = 0; j < m.size; j++) {
			os << m.matrix[i][j] << " ";
		}
		os << std::endl;
	}

	return os;
}
