#include <iostream>
#include <sstream>
#include <stdexcept>
#include "matrix_u.h"

using namespace std;

int& Matrix_U::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
	if ((iRow < 0) || (iCol < 0) || (iRow >= nRow_) || (iCol >= nCol_)) { throw invalid_argument("Error: Out of range"); }
	return pdata_[nCol_ * iRow + iCol];
}
const int& Matrix_U::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
	if ((iRow < 0) || (iCol < 0) || (iRow >= nRow_) || (iCol >= nCol_)) { throw invalid_argument("Error: Out of range"); }
	return pdata_[nCol_ * iRow + iCol];
}
Matrix_U::Matrix_U()
{
	pdata_ = new int[nRow_ * nCol_];
}
Matrix_U::Matrix_U(ptrdiff_t x, ptrdiff_t y)
{
	if ((x <= 0) || (y <= 0)) throw invalid_argument("Error: Size can't be less or equals 0");
	nRow_ = x;
	nCol_ = y;
	pdata_ = new int[nRow_ * nCol_];
}
Matrix_U::~Matrix_U()
{
	delete[] pdata_;
}
Matrix_U& Matrix_U::operator=(Matrix_U& z)
{
	for (ptrdiff_t i = 0; i < nRow_; i++)
	{
		for (ptrdiff_t j = 0; j < nCol_; j++)
		{
			at(i, j) = z.at(i, j);
		}
	}
	return *this;
}
Matrix_U& Matrix_U::operator+=(Matrix_U& z)
{
	for (ptrdiff_t i = 0; i < nRow_; i++)
	{
		for (ptrdiff_t j = 0; j < nCol_; j++)
		{
			at(i, j) = at(i, j) + z.at(i, j);
		}
	}
	return *this;
}
Matrix_U& Matrix_U::operator*=(Matrix_U& z)
{
	for (int i = 0; i < nRow_; i++)
	{
		for (int j = 0; j < nCol_; j++)
		{
			at(i, j) = at(i, j) * z.at(j, i);
		}
	}
	return *this;
}

std::ostream& Matrix_U::writeTo(std::ostream& ostrm)
{
	for (ptrdiff_t i = 0; i < nRow_ * nCol_; i++)
		ostrm << pdata_[i] << " ";
	return ostrm;
}
