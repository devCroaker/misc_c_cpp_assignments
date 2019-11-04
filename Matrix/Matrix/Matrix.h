#pragma once
#include <cstdio>
#include <fstream>
#include <iostream>
#include "Input.h"

class Matrix
{
private:
	int size;
	
public:
	int **matrix;

	Matrix();
	Matrix(int);
	Matrix(const Matrix&);
	~Matrix();

	Matrix* next;
	int operation;

	void operator=(const Matrix &m)const;
	Matrix operator +(Matrix &m);
	Matrix operator -(Matrix &m);
	Matrix operator *(Matrix &m);
	Matrix operator ++(int);
	Matrix operator --(int);
	Matrix& operator ++();
	Matrix& operator --();
	Matrix operator ~();
	Matrix operator ^(Matrix &m);

	friend std::ostream& operator <<(std::ostream& os, Matrix &m);
	void printMatrix();
	int getSize();
};

