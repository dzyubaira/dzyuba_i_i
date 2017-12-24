#include <iostream>
#include <sstream>
#include "matrix_r.h"

int main()
{
	using namespace std;
	Matrix_R a();
	Matrix_R b(2, 2);
	b.at(0, 0) = 2;
	b.at(0, 1) = 3;
	b.at(1, 0) = 4;
	b.at(1, 1) = 5;
	Matrix_R c(2, 2);
	c.at(0, 0) = 0;
	c.at(0, 1) = 0;
	c.at(1, 0) = 0;
	c.at(1, 1) = 0;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	c = b;
	cout << "c = b = " << c << endl;
	b += c;
	cout << "b += c = " << b << endl;
	b *= c;
	cout << "b *= c = " << b << endl;
	return 0;
}