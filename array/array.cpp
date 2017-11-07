#include <iostream>
#include <sstream>
#include "array.h"

int& Array::operator[] (const ptrdiff_t i)
{
	return pdata_[i];
}
const int& Array::operator[](const ptrdiff_t i) const
{
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
	int l = size;
	return l;
}
void Array::insert(int z)
{
	size++;
	pdata_[size - 1] = z;
}
void Array::remove(int z)
{
	for (ptrdiff_t i = 0; i < size; i++)
	{
		if (pdata_[i] == z)
		{
			for (ptrdiff_t j = i; j < size - 1; j++)
				pdata_[j] = pdata_[j + 1];
			size--;
			i--;
		}
	}
}

std::ostream& Array::writeTo(std::ostream& ostrm)
{
	for (ptrdiff_t i = 0; i < size; i++)
		ostrm << pdata_[i] << " ";
	return ostrm;
}