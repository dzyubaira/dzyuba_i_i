#ifndef KVATERNION_H
#define KVATERNION_H
#include <iosfwd>

struct Kvat
{
	Kvat() = default;
	~Kvat() = default;
	Kvat(double a, double b, double c, double d);
	Kvat& operator+=(Kvat& z);
	Kvat& operator-=(Kvat& z);
	Kvat& operator*=(double z);
	Kvat& operator*=(Kvat& z);
	Kvat& operator/=(double z);

	double x1 = 0;
	double x2 = 0;
	double x3 = 0;
	double x4 = 0;

	std::ostream& writeTo(std::ostream& ostrm);
	std::istream& readFrom(std::istream& istrm);
};

double det(Kvat& z);

inline std::ostream& operator<<(std::ostream& ostrm, Kvat& z)
{
	return z.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Kvat& z)
{
	return z.readFrom(istrm);
}

#endif
