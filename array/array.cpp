#include <iostream>
#include <sstream>
#include <stdexcept>
#include "array.h"

using namespace std;

int& Array::operator[] (const ptrdiff_t i)
{
	return pdata_[i];
}
const int& Array::operator[](const ptrdiff_t i) const
{
	if ((i < 0) || (i >= size)) { throw invalid_argument("Error2: Out of range"); }
	return pdata_[i];
}

Array::Array()
{
	pdata_ = new int[size];
}
Array::Array(Array& z)
{
	size = z.size;
	pdata_ = new int[size];
	for (ptrdiff_t i = 0; i < size; i++)
		pdata_[i] = z.pdata_[i];
}
Array::Array(ptrdiff_t z)
{
	if (z <= 0) { throw invalid_argument("Error: Size can't be less or equals 0"); }
	size = z;
	pdata_ = new int[size];
}
Array::~Array()
{
	delete[] pdata_;
}

Array& Array::operator=(Array& z)
{
	size = z.size;
	pdata_ = new int[size];
	for (ptrdiff_t i = 0; i < size; i++)
		pdata_[i] = z.pdata_[i];
	return *this;
}
int Array::length()
{
	return size;
}
void Array::remove(int z)
{
	for (ptrdiff_t i = 0; i < size; i++)
	{
		if (pdata_[i] == z)
		{
			for (ptrdiff_t j = i; j < size - 1; j++)
				pdata_[j] = pdata_[j + 1];
			size = size - 1;
			i = i - 1;
		}
	}
}
void Array::insert_i(ptrdiff_t z, int n)
{
	int* pdata_n = new int[size];
	for (ptrdiff_t i = 0; i < size; i++)
	{
		pdata_n[i] = pdata_[i];
	}
	size = size + 1;
	pdata_ = new int[size];
	for (ptrdiff_t i = 0; i < z; i++)
	{
		pdata_[i] = pdata_n[i];
	}
	pdata_[z] = n;
	for (ptrdiff_t i = z + 1; i < size; i++)
	{
		pdata_[i] = pdata_n[i - 1];
	}
	delete[] pdata_n;
}
void Array::remove_i(ptrdiff_t z)
{
	for (ptrdiff_t i = z; i < size - 1; i++)
	{
		pdata_[i] = pdata_[i + 1];
	}
	size = size - 1;
}
std::ostream& Array::writeTo(std::ostream& ostrm)
{
	for (ptrdiff_t i = 0; i < size; i++)
		ostrm << pdata_[i] << " ";
	return ostrm;
}
