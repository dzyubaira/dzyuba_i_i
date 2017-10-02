#ifndef RATIONAL_H
#define RATIONAL_H
#include <iosfwd>
#include <iostream>

struct Rational
{
	Rational() {};
	explicit Rational(const int numerator);
	Rational(const int numerator, const int denominator);
	bool operator==(const Rational& rhs) const { return (num == rhs.num) && (denom == rhs.denom); }
	bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
	Rational& norm(Rational rhs);

	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs) { return operator+=(Rational(rhs)); }
	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int rhs) { return operator-=(Rational(rhs)); }
	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int rhs) { return operator*=(Rational(rhs)); }
	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int rhs) { return operator/=(Rational(rhs)); }
	Rational& operator^=(const int rhs);
	std::ostream& writeTo(std::ostream& ostrm);
	std::istream& readFrom(std::istream& istrm);

	int num{ 0 };
	int denom{ 1 };

	static const char leftBrace{ '(' };
	static const char separator{ '/' };
	static const char rightBrace{ ')' };

private:
	void nod();

};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}

bool testParse(const std::string& str);

#endif