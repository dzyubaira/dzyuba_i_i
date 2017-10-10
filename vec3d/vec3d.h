#ifndef VEC3D_H
#define VEC3D_H
#include <iosfwd>
#include <iostream>

struct Vec3d
{
public:
	Vec3d() = default;
	~Vec3d() = default;
	Vec3d(const double xv, const double yv, const double zv);
	Vec3d(const Vec3d& v);

	bool operator==(const Vec3d& v) const { return (x == v.x) && (y == v.y) && (z == v.z); }
	bool operator!=(const Vec3d& v) const { return !operator==(v); }

	Vec3d& operator=(const Vec3d v);
	Vec3d& operator+=(const Vec3d v);
	Vec3d& operator-=(const Vec3d v);
	Vec3d& operator*=(const int n);
	Vec3d& operator/=(const int n); 
	Vec3d& operator*=(const Vec3d v);

	std::ostream& writeTo(std::ostream& ostrm);
	std::istream& readFrom(std::istream& istrm);

public:
	double x{ 0.0 };
	double y{ 0.0 };
	double z{ 0.0 };
	static const char separator{ ',' };
	static const char leftBrace{ '(' };
	static const char rightBrace{ ')' };
};

double length(const Vec3d v);

inline std::istream& operator >> (std::istream& istrm, Vec3d& v)
{
	return v.readFrom(istrm);
}
inline std::ostream& operator << (std::ostream& ostrm, Vec3d& v)
{
	return v.writeTo(ostrm);
}

bool testParse(const std::string& str);
#endif