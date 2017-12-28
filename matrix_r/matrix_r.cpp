#include <iostream>
#include <sstream>
#include <stdexcept>
#include "matrix_r.h"  

using namespace std;

int& Matrix_R::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
	if ((iRow < 0) || (iCol < 0) || (iRow >= nRow_) || (iCol >= nCol_)) { throw invalid_argument("Error: Out of range"); }
	return pRows_[iRow][iCol];
}
const int& Matrix_R::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
	if ((iRow < 0) || (iCol < 0) || (iRow >= nRow_) || (iCol >= nCol_)) { throw invalid_argument("Error: Out of range"); }
	return pRows_[iRow][iCol];
}
Matrix_R::Matrix_R()
{
	pRows_ = new int*[nRow_];
	pRows_[0] = new int[nRow_*nCol_];
	for (int i = 0; i < nRow_ - 1; i++)
	{
		pRows_[i + 1] = new int[nRow_*nCol_ - (i + 1)*nCol_];
	}
}
Matrix_R::Matrix_R(ptrdiff_t row, ptrdiff_t col)
{
	if ((row <= 0) || (col <= 0)) throw invalid_argument("Error: Size can't be less or equals 0");
	nRow_ = row;
	nCol_ = col;
	pRows_ = new int*[nRow_];
	pRows_[0] = new int[nRow_*nCol_];
	for (int i = 0; i < nRow_ - 1; i++)
	{
		pRows_[i + 1] = new int[nRow_*nCol_ - (i + 1)*nCol_];
	}
}
Matrix_R::~Matrix_R()
{
	for (int i = 0; i < nRow_; i++)
		delete[] pRows_[i];
	delete[] pRows_;
}
Matrix_R& Matrix_R::operator=(Matrix_R& z)
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
Matrix_R& Matrix_R::operator+=(Matrix_R& z)
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
Matrix_R& Matrix_R::operator*=(Matrix_R& z)
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

std::ostream& Matrix_R::writeTo(std::ostream& ostrm)
{
	for (ptrdiff_t i = 0; i < nRow_; i++)
	{
		for (ptrdiff_t j = 0; j < nCol_; j++)
		{
			ostrm << at(i, j) << " ";
		}
	}
	return ostrm;
}
