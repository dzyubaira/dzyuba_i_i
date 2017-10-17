#ifndef VEC3DT_H
#define VEC3DT_H
#include <iosfwd>
#include <iostream>

template <typename T>
struct Vec3dT
{
public:
	Vec3dT<T>::Vec3dT() = default;
	Vec3dT<T>::~Vec3dT() = default;
	Vec3dT(const T xv, const T yv, const T zv)
		:x(xv)
		, y(yv)
		, z(zv)
	{
	}
	Vec3dT(const Vec3dT& v)
		:x(v.x)
		, y(v.y)
		, z(v.z)
	{
	}

	bool operator==(const Vec3dT& v) const { return (x == v.x) && (y == v.y) && (z == v.z); }
	bool operator!=(const Vec3dT& v) const { return !operator==(v); }

	Vec3dT& operator=(const Vec3dT v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}
	Vec3dT& operator+=(const Vec3dT v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	Vec3dT& operator-=(const Vec3dT v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	Vec3dT& operator*=(const T n)
	{
		x = x * n;
		y = y * n;
		z = z * n;
		return *this;
	}
	Vec3dT& operator/=(const T n)
	{
		x = x / n;
		y = y / n;
		z = z / n;
		return *this;
	}
	Vec3dT& operator*=(const Vec3dT v)
	{
		x = x * v.x;
		y = y * v.y;
		z = z * v.z;
		return *this;
	}

	std::ostream& Vec3dT<T>::writeTo(std::ostream& ostrm)
	{
		ostrm << x << " " << y << " " << z;
		return ostrm;
	}
	std::istream& Vec3dT<T>::readFrom(std::istream& istrm)
	{
		T xx(T());
		T yy(T());
		T zz(T());
		istrm >> x >> " " >> y >> " " >> z;
		if (istrm.good())
		{
			xx = x;
			yy = y;
			zz = z;
		}
		return istrm;
	}

public:
	T x{ T() };
	T y{ T() };
	T z{ T() };
};

template <typename T>
T length(const Vec3dT<T> v)
{
	T l = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return l;
}

template <typename T>
inline std::istream& operator >> (std::istream& istrm, Vec3dT<T>& v)
{
	return v.readFrom(istrm);
}

template <typename T>
inline std::ostream& operator << (std::ostream& ostrm, Vec3dT<T>& v)
{
	return v.writeTo(ostrm);
}

template <typename T>
bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Vec3dT a;
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
#endif