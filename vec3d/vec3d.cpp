#include <iostream>
#include <sstream>
#include <cmath>
#include "vec3d.h"

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Vec3d a;
	istrm >> a;
	if (istrm.good())
	{
		cout << "Read success: " << str << " -> " << a << endl;
	}
	else
	{
		cout << "Read error: " << str << " -> " << a << endl;
	}
	return istrm.good();
}

Vec3d::Vec3d(const double xv, const double yv, const double zv)
	:x(xv)
	, y(yv)
	, z(zv)
{
}
Vec3d::Vec3d(const Vec3d& v)
	:x(v.x)
	, y(v.y)
	, z(v.z)
{
}

Vec3d& Vec3d::operator=(const Vec3d v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}
Vec3d& Vec3d::operator+=(const Vec3d v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
Vec3d& Vec3d::operator-=(const Vec3d v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
Vec3d& Vec3d::operator*=(const int n)
{
	x = x * n;
	y = y * n;
	z = z * n;
	return *this;
}
Vec3d& Vec3d::operator/=(const int n)
{
	x = x / n;
	y = y / n;
	z = z / n;
	return *this;
}
Vec3d& Vec3d::operator*=(const Vec3d v)
{
	x = x * v.x;
	y = y * v.y;
	z = z * v.z;
	return *this;
}

double length(const Vec3d v)
{
	double l = sqrt (v.x * v.x + v.y * v.y + v.z * v.z);
	return l;
}

std::ostream& Vec3d::writeTo(std::ostream& ostrm)
{
	ostrm << leftBrace << x << separator << y << separator << z << rightBrace;
	return ostrm;
}

std::istream& Vec3d::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	char rightBrace(0);
	char comma(0);
	double xx(0);
	double yy(0);
	double zz(0);
	istrm >> leftBrace >> x >> comma >> y >> comma >> z >> rightBrace;
	if (istrm.good())
	{
		if ((Vec3d::rightBrace == rightBrace) && (Vec3d::separator == comma) && (Vec3d::leftBrace == leftBrace))
		{
			xx = x;
			yy = y;
			zz = z;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}