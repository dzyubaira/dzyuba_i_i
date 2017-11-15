#ifndef MATRIX_U_H
#define MATRIX_U_H
#include <iosfwd>

class Matrix_U
{
public:
	int& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
	const int& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;
	Matrix_U();
	Matrix_U(ptrdiff_t x, ptrdiff_t y);
	~Matrix_U();
	Matrix_U& operator=(Matrix_U& z);
	Matrix_U& operator+=(Matrix_U& z);
	Matrix_U& operator*=(Matrix_U& z);

	std::ostream& writeTo(std::ostream& ostrm);

private:
	ptrdiff_t nRow_{ 0 };
	ptrdiff_t nCol_{ 0 };
	int* pdata_{ nullptr };
};

inline std::ostream& operator << (std::ostream& ostrm, Matrix_U& z)
{
	return z.writeTo(ostrm);
}

#endif