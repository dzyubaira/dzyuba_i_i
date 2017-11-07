#include <iostream>
#include <sstream>
#include "array.h"

int main()
{
	using namespace std;
	Array a(3);
	a[0] = 4;
	a[1] = 4;
	a[2] = 6;
	cout << "Array a:  " << a << endl;
	Array b(a);
	cout << "Array b(a):  " << b << endl;
	Array c;
	c = b;
	cout << "Array c = b:  " << c << endl;
	int d = c.length();
	cout << "length(c) = " << d << endl;
	c.insert(3);
	cout << "c.insert(3) = " << c << endl;
	int e = c.length();
	cout << "length(c) = " << e << endl;
	c.remove(4);
	cout << "c.remove(4) = " << c << endl;
	int f = c.length();
	cout << "length(c) = " << f << endl;
	system("pause");
	return 0;
}