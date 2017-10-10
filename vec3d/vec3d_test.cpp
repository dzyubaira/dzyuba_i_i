#include <iostream>
#include <sstream>
#include "vec3d.h"

int main()
{
	using namespace std;
	testParse("(1,2,4)");
	testParse("5,6,7)");
	Vec3d z;
	Vec3d a(2.5, 3.6, 4.6);
	cout << "a = " << a << endl;
	Vec3d b(a);
	cout << "b(a) = " << b << endl;
	Vec3d c = b;
	cout << "c = b" << endl << "c = " << c << endl;
	Vec3d d(3.7, 8.4, 8.9);
	cout << "d = " << d << endl;
	if (b == c)
		cout << "b == c" << endl;
	if (c != d)
		cout << "c != d" << endl;
	c += d;
	cout << "c += d = " << c << endl;
	c -= d;
	cout << "c -= d = " << c << endl;
	int e = 3;
	cout << "e = " << e << endl;
	c *= e;
	cout << "c *= e = " << c << endl;
	c /= e;
	cout << "c /= e = " << c << endl;
	c *= d;
	cout << "c *= d = " << c << endl;
	double l = length(c);
	cout << "length(c) = " << l << endl;
	return 0;
}