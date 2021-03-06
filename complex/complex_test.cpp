#include <iostream>
#include <sstream>
#include "complex.h"

int main()
{
	using namespace std;

	Complex z;
	z += Complex(8.0);
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");
	Complex x = Complex(8, 0.0000001);
	Complex y = Complex(8, 0.00000001);
	cout << "z = " << z << endl << "x = " << x << endl << "y = " << y << endl;
	if (x == z)
	{
		cout << "x == z" << endl;
	}
	else
	{
		cout << "x != z" << endl;
	}
	if (z == y)
	{
		cout << "z == y" << endl;
	}
	else
	{
		cout << "z != y" << endl;
	}
	x += z;
	cout << "x += z = " << x << endl;
	Complex a = Complex(4, 5);
	z -= a;
	cout << "a = " << a << endl << "z -= a = " << z << endl;
	Complex b = Complex(7, 2);
	a *= b;
	cout << "b = " << b << endl << "a *= b =" << a << endl;
	double c = 3.2;
	b *= c;
	cout << "c = " << c << endl << "b *= c = " << b << endl;
	Complex d = Complex(3, 4);
	Complex e = Complex(5, 6);
	Complex f = e + d;
	Complex g = e - d;
	cout << "d = " << d << endl << "e = " << e << endl << "d + e = " << f << endl << "e - d = " << g << endl;
	return 0;
}
