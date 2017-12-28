#include <iostream>
#include <sstream>
#include "matrix_u.h"

int main()
{
	using namespace std;
	Matrix_U a();
	Matrix_U b(2, 2);
	Matrix_U c(2, 2);
	b.at(0, 0) = 1;
	b.at(0, 1) = 2;
	b.at(1, 0) = 3;
	b.at(1, 1) = 4;
	c.at(0, 0) = 5;
	c.at(0, 1) = 6;
	c.at(1, 0) = 7;
	c.at(1, 1) = 8;
	cout << "b = " << b << endl << "c = " << c << endl;
	b = c;
	cout << "b = c = " << b << endl;
	b += c;
	cout << "b = b += c " << endl << "b = " << b << endl;
	b *= c;
	cout << "b = b *= c " << endl << "b = " << b << endl;
	try
	{
		Matrix_U d(-5, -5);
	}
	catch (const invalid_argument& except)
	{
		cout << except.what() << endl;
	}
	cout << "try c.at(5, 5) = 8" << endl;
	try
	{
		c.at(5, 5) = 8;
	}
	catch (const invalid_argument& except)
	{
		cout << except.what() << endl;
	}
	return 0;
}
