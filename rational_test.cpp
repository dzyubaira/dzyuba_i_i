#include <iostream>
#include <sstream>
#include "rational.h"

int main()
{
	using namespace std;
	Rational z = Rational(2, 3);
	testParse("(2/5)");
	testParse("(3,5)");

	Rational a = Rational(2, 3);
	cout << "a = " << a << endl;
	Rational b = Rational(5, 2);
	a += b;
	cout << "b = " << b << endl << "a += b = " << a << endl;
	Rational c = Rational(3, 4);
	b -= c;
	cout << "c = " << c << endl << "b -= c = " << b << endl;
	Rational d = Rational(7, 2);
	c *= d;
	cout << "d = " << d << endl << "c *= d = " << c << endl;
	int e = 3;
	d *= e;
	cout << "e = " << e << endl << "d *= e = " << d << endl;
	Rational f = Rational(3, 8);
	cout << "f = " << f << endl;
	Rational g = Rational(5, 9);
	f /= g;
	cout << "g = " << g << endl << "f /= g = " << f << endl;
	int h = 2;
	g /= h;
	cout << "h = " << h << endl << "g /= h = " << g << endl;
	Rational i = Rational(2, 5);
	Rational j = Rational(4, 7);
	Rational k = i + j;
	Rational l = i - j;
	cout << "i = " << i << endl << "j = " << j << endl << "i + j = " << k << endl << "i - j = " << l << endl;
	int m = 3;
	i ^= m;
	cout << "m = " << m << endl << "i ^= m = " << i << endl;
	return 0;
}