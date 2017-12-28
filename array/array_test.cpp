#include <iostream>
#include <sstream>
#include "array.h"

int main()
{
	using namespace std;
	cout << "try Array k(-4)" << endl;
	try
	{
		Array k(-4);
	}
	catch (const invalid_argument& except)
	{
		cout << except.what() << endl;
	}
	Array a(5);
	a[0] = 4;
	a[1] = 4;
	a[2] = 6;
	a[3] = 7;
	a[4] = 8;
	cout << "Array a:  " << a << endl;
	cout << "try a[-6] = 8" << endl;
	try
	{
		a[-6] = 8;
	}
	catch (const invalid_argument& except)
	{
		cout << except.what() << endl;
	}
	Array b(a);
	cout << "Array b(a):  " << b << endl;
	Array c;
	c = b;
	cout << "Array c = b:  " << c << endl;
	int d = c.length();
	cout << "length(c) = " << d << endl;
	c.remove(4);
	cout << "c.remove(4) = " << c << endl << "length(c) = " << c.length() << endl;
	c.insert_i(1, 5);
	cout << "c.insert_i(1,5) = " << c << endl << "length(c) = " << c.length() << endl;
	c.remove_i(1);
	cout << "c.remove_i(1) = " << c << endl << "length(c) = " << c.length() << endl;
	return 0;
}
