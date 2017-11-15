#include <iostream>
#include <sstream>
#include "kvaternion.h"

int main()
{
	using namespace std;
	Kvat a;
	Kvat b(2.5, 6.7, 3.5, 1.8);
	a = b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	a += b;
	cout << "a += b = " << a << endl;
	Kvat c(4.8, 9.6, 8.3, 6.4);
	cout << "c = " << c << endl;
	c -= b;
	cout << "c -= b = " << c << endl;
	Kvat d(4.5, 7.8, 4.5, 3.4);
	cout << "d = " << d << endl;
	double e = 3;
	cout << "e = " << e << endl;
	d *= e;
	cout << "d *= e = " << d << endl;
	Kvat f(3, 6, 7, 8);
	Kvat g(2, 8, 6, 4);
	cout << "f = " << f << endl << "g = " << g << endl;
	f *= g;
	cout << "f *= g = " << f << endl;
	Kvat h(4, 6, 8, 10);
	double i = 2;
	cout << "h = " << h << endl << "i = " << i << endl;
	h /= i;
	cout << "h /= i = " << h << endl;
	Kvat j(3, 6, 8, 5);
	double k = det(j);
	cout << "j = " << j << endl << "det(j) = " << k << endl;
	return 0;
}
