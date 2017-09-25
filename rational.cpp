#include <iostream>
#include <sstream>
#include "rational.h"

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Rational z;
	istrm >> z;
	if (istrm.good())
	{
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else
	{
		cout << "Read error: " << str << " -> " << z << endl;
	}
	return istrm.good();
}

int nod(int a, int b)
{
	int c = 1;
	if (a > b)
	{
		for (int i = 1; i <= b; i++)
		{
			if ((a % i == 0) && (b % i == 0))
				c = i;
		}
	}
	else
	{
		for (int i = 1; i <= a; i++)
		{
			if ((a % i == 0) && (b % i == 0))
				c = i;
		}
	}
	return c;
}

Rational::Rational(const int numerator)
	: Rational(numerator, 1)
{
}

Rational::Rational(const int numerator, const int denominator)
	: num(numerator)
	, denom(denominator)
{
}

Rational& Rational::operator+=(const Rational& rhs)
{
	num = num*rhs.denom + rhs.num*denom;
	denom *= rhs.denom;
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
	num = num*rhs.denom - rhs.num*denom;
	denom *= rhs.denom;
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
	num *= rhs.num;
	denom *= rhs.denom;
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
	num *= rhs.denom;
	denom *= rhs.num;
	return *this;
}

Rational& Rational::operator^=(const int rhs)
{
	for (int i = 0; i < rhs; i++)
	{
		num *= num;
		denom *= denom;
	}
	return *this;
}

Rational operator+ (const Rational& lhs, const Rational& rhs)
{
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational operator- (const Rational& lhs, const Rational& rhs)
{
	Rational dif(lhs);
	dif -= rhs;
	return dif;
}

std::ostream& Rational::writeTo(std::ostream& ostrm)
{
	int t = nod(num, denom);
	num /= t;
	denom /= t;
	ostrm << num << separator << denom;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
	char rightBrace(0);
	char leftBrace(0);
	char comma(0);
	int numerator(0);
	int denominator(0);
	istrm >> leftBrace >> numerator >> comma >> denominator >> rightBrace;
	if (istrm.good())
	{
		if ((Rational::rightBrace == rightBrace) && (Rational::separator == comma) && (Rational::leftBrace == leftBrace))
		{
			num = numerator;
			denom = denominator;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}