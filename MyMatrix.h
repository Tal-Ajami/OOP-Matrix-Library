#pragma once
#include <iostream>
using namespace std;

class MyMatrix
{
private:
	//number of rows
	int _m;
	//number of cols
	int _n;
	int** mat = nullptr;

public:
	MyMatrix(int rows=3, int cols=3);
	MyMatrix(const MyMatrix& other);
	void deletemat();
	~MyMatrix();

	int get_m() const { return this->_m; }
	int get_n() const { return this->_n; }
	void set_m(int num) { this->_m = num; }
	void set_n(int num) { this->_n = num; }
	void fill_mat();
	void print_mat() const;

	friend MyMatrix operator+(const MyMatrix& m1, const MyMatrix& m2);
	friend MyMatrix operator-(const MyMatrix& m1, const MyMatrix& m2);
	friend MyMatrix operator*(const MyMatrix& m1, const MyMatrix& m2);
	friend MyMatrix operator*(const MyMatrix& m, int num);
	friend MyMatrix operator*(int num, const MyMatrix& m);
	MyMatrix& operator=(const MyMatrix& other);
	friend bool operator==(const MyMatrix& m1, const MyMatrix& m2);

	friend ostream& operator<<(ostream& out, const MyMatrix& m);
	friend istream& operator>>(istream& in, MyMatrix& m);
	int* operator[](int row);
	operator double();

	
};

