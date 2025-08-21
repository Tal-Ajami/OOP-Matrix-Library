#include "MyMatrix.h"
#include <iostream>

MyMatrix::MyMatrix(int rows, int cols)
{
	if (rows <= 0 || cols <= 0)
	{
		throw exception("Rows and columns must be positive integers.");
	}

	this->_m = rows;
	this->_n = cols;
	this->mat = new int* [rows];
	for (int i = 0; i < rows; i++) {this->mat[i] = new int[cols];}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) { this->mat[i][j] = 0; }
	}
}

void MyMatrix::deletemat()
{
	if (this->mat != nullptr) {
		for (int i = 0; i < this->_m; i++) { delete[] this->mat[i]; }
		delete[] this->mat;
		this->mat = nullptr;
	}
}

MyMatrix::MyMatrix(const MyMatrix& other)
{
	this->deletemat();
	this->_m = other._m;
	this->_n = other._n;
	this->mat = new int* [other._m];
	for (int i = 0; i < other._m; i++) { this->mat[i] = new int[other._n]; }

	for (int i = 0; i < other._m; i++) {
		for (int j = 0; j < other._n; j++) { this->mat[i][j] = other.mat[i][j]; }
	}
}

MyMatrix::~MyMatrix()
{
	this->deletemat();
	this->_m = 0;
	this->_n = 0;
}

void MyMatrix::print_mat() const
{
	for (int i = 0; i < this->_m; i++) {
		for (int j = 0; j < this->_n; j++) {cout << this->mat[i][j]<< ' '; }
		cout << endl;
	}
}


void MyMatrix::fill_mat()
{
	for (int i = 0; i < this->_m; i++) {
		for (int j = 0; j < this->_n; j++) {
			cout << "enter a value for place number " << j + 1 << " in line " << i + 1 << endl;
			cin >> this->mat[i][j];
		}
	}
}

MyMatrix operator+(const MyMatrix& m1, const MyMatrix& m2)
{
	if (m1._m != m2._m || m1._n != m2._n) {
		throw exception("The matrices are not the same size.");
	}
	MyMatrix m3(m1._m, m1._n);
	for (int i = 0; i < m1._m; i++) {
		for (int j = 0; j < m1._n; j++) { m3.mat[i][j] = m1.mat[i][j] + m2.mat[i][j]; }
	}
	return m3;
}

MyMatrix operator-(const MyMatrix& m1, const MyMatrix& m2)
{
	if (m1._m != m2._m || m1._n != m2._n) {
		throw exception("The matrices are not the same size.");
	}
	MyMatrix m3(m1._m, m1._n);
	for (int i = 0; i < m1._m; i++) {
		for (int j = 0; j < m1._n; j++) { m3.mat[i][j] = m1.mat[i][j] - m2.mat[i][j]; }
	}
	return m3;
}

MyMatrix operator*(const MyMatrix& m1, const MyMatrix& m2)
{
	if (m1._n != m2._m) {
		throw exception("The matrices are not suitable for multiplication.");
	}

	MyMatrix result(m1.get_m(), m2.get_n());

	for (int i = 0; i < m1.get_m(); i++) {
		for (int j = 0; j < m2.get_n(); j++) {
			result.mat[i][j] = 0; 
			for (int k = 0; k < m1.get_n(); k++) {
				result.mat[i][j] += m1.mat[i][k] * m2.mat[k][j];
			}
		}
	}
	return result;	
}

MyMatrix operator*(const MyMatrix& m, int num)
{
	MyMatrix result(m);
	for (int i = 0; i < m.get_m(); i++) {
		for (int j = 0; j < m.get_n(); j++) {
			result.mat[i][j] = result.mat[i][j] * num;
		}
	}
	return result;
}

MyMatrix operator*(int num, const MyMatrix& m)
{
	MyMatrix result(m);
	for (int i = 0; i < m.get_m(); i++) {
		for (int j = 0; j < m.get_n(); j++) {
			result.mat[i][j] = result.mat[i][j] * num; }
	}
	
	return result;
}

MyMatrix& MyMatrix::operator=(const MyMatrix& other)
{
	this->deletemat();
	this->_m = other._m;
	this->_n = other._n;

	this->mat = new int* [other._m];
	for (int i = 0; i < other._m; i++) {
		this->mat[i] = new int[other._n];
	}

	for (int i = 0; i < other._m; i++) {
		for (int j = 0; j < other._n; j++) {
			this->mat[i][j] = other.mat[i][j];
		}
	}
	return *this;
}
int* MyMatrix::operator[](int row)
{
	if (row>this->_m){throw exception("Row does not exist");}
	return this->mat[row];
}
MyMatrix::operator double()
{
	double sum = 0;
	for (int i = 0; i < this->get_m(); i++) {
		for (int j = 0; j < this->get_n(); j++) {
			sum += this->mat[i][j];
		}
	}
	return sum;
}
bool operator==(const MyMatrix& m1, const MyMatrix& m2)
{
	if (m1._m != m2._m || m1._n != m2._n) { return false;}
	for (int i = 0; i < m1.get_m(); i++) {
		for (int j = 0; j < m1.get_n(); j++) {
			if(m1.mat[i][j] != m2.mat[i][j]){ return false; }
		}
	}
	return true;

}

ostream& operator<<(ostream& out, const MyMatrix& m) {
	for (int i = 0; i < m._m; i++) {
		for (int j = 0; j < m._n; j++) {
			out << m.mat[i][j] << " "; 
		}
		out << endl;
	}
	return out; 
}


istream& operator>>(istream& in, MyMatrix& m) {
	cout << "Filling the matrix (" << m._m << "x" << m._n << "):\n";
	for (int i = 0; i < m._m; i++) {
		for (int j = 0; j < m._n; j++) {
			cout << "Enter value for cell [" << i + 1 << "][" << j + 1 << "]: ";
			in >> m.mat[i][j]; 
		}
	}
	return in; 
}



