#include <iostream>
#include <sstream>
#include "matrix_r.h"

int main()
{
	using namespace std;
	Matrix_R a();
	cout << "try Matrix_R d(-3, -4)" << endl;
	try
	{
		Matrix_R d(-3, -4);
	}
	catch(const invalid_argument& except)
	{
		cout << except.what() << endl;
	}
	Matrix_R b(2, 2);
	b.at(0, 0) = 2;
	b.at(0, 1) = 3;
	b.at(1, 0) = 4;
	b.at(1, 1) = 5;
	cout << "b = " << b << endl;
	cout << "try b.at(-1,-1) = 9" << endl;
	try
	{
		b.at(-1, -1) = 9;
	}
	catch (const invalid_argument& except)
	{
		cout << except.what() << endl;
	}
	Matrix_R c(2, 2);
	c.at(0, 0) = 0;
	c.at(0, 1) = 0;
	c.at(1, 0) = 0;
	c.at(1, 1) = 0;
	cout << "c = " << c << endl;
	c = b;
	cout << "c = b = " << c << endl;
	b += c;
	cout << "b += c = " << b << endl;
	b *= c;
	cout << "b *= c = " << b << endl;
	return 0;
}
