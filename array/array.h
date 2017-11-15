#ifndef ARRAY_H
#define ARRAY_H
#include <iosfwd>

class Array
{
public:
	int& operator[] (const ptrdiff_t i);
	const int& operator[](const ptrdiff_t i) const;

	Array();
	Array(Array& z);
	Array(ptrdiff_t z);
	~Array();
	Array& operator=(Array& z);
	int length();
	void remove(int z);
	void insert_i(ptrdiff_t z, int n);
	void remove_i(ptrdiff_t z);

	std::ostream& writeTo(std::ostream& ostrm);

private:
	ptrdiff_t size{ 0 };
	int* pdata_{ nullptr };
};

inline std::ostream& operator << (std::ostream& ostrm, Array& z)
{
	return z.writeTo(ostrm);
}

#endif
