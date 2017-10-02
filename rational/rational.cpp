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

void Rational::nod()
{
	int c = 1;
	if (num > denom)
	{
		for (int i = 1; i <= denom; i++)
		{
			if ((num % i == 0) && (denom % i == 0))
				c = i;
		}
	}
	else
	{
		for (int i = 1; i <= num; i++)
		{
			if ((num % i == 0) && (denom % i == 0))
				c = i;
		}
	}
	num /= c;
	denom /= c;
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
	nod();
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
	num = num*rhs.denom - rhs.num*denom;
	denom *= rhs.denom;
	nod();
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
	num *= rhs.num;
	denom *= rhs.denom;
	nod();
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
	num *= rhs.denom;
	denom *= rhs.num;
	nod();
	return *this;
}

Rational& Rational::operator^=(const int rhs)
{
	int t = num;
	int s = denom;
	for (int i = 0; i < rhs; i++)
	{
		num *= t;
		denom *= s;
	}
	nod();
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

