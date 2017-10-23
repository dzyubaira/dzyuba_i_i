#include <iostream>
#include <sstream>
#include "kvaternion.h"

Kvat::Kvat(double a, double b, double c, double d)
	:x1(a)
	, x2(b)
	, x3(c)
	, x4(d)
{
}
Kvat& Kvat::operator+=(Kvat& z)
{
	x1 += z.x1;
	x2 += z.x2;
	x3 += z.x3;
	x4 += z.x4;
	return*this;
}
Kvat& Kvat::operator-=(Kvat& z)
{
	x1 -= z.x1;
	x2 -= z.x2;
	x3 -= z.x3;
	x4 -= z.x4;
	return*this;
}
Kvat& Kvat::operator*=(double z)
{
	x1 *= z;
	x2 *= z;
	x3 *= z;
	x4 *= z;
	return*this;
}
Kvat& Kvat::operator*=(Kvat& z)
{
	x1 *= z.x1;
	x2 *= z.x3;
	x3 *= z.x2;
	x4 *= z.x4;
	return*this;
}
Kvat& Kvat::operator/=(double z)
{
	x1 /= z;
	x2 /= z;
	x3 /= z;
	x4 /= z;
	return*this;
}

double det(Kvat& z)
{
	double a;
	a = z.x1*z.x4 - z.x2*z.x3;
	return a;
}

std::ostream& Kvat::writeTo(std::ostream& ostrm)
{
	ostrm << x1 << "   " << x2 << "   " << x3 << "   " << x4;
	return ostrm;
}
std::istream& Kvat::readFrom(std::istream& istrm)
{
	istrm >> x1 >> x2 >> x3 >> x4;
	return istrm;
}