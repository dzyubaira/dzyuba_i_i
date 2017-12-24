#ifndef MATRIX_R_H
#define MATRIX_R_H
#include <iosfwd>

class Matrix_R
{
public:
	int& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
	const int& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;
	Matrix_R();
	Matrix_R(ptrdiff_t row, ptrdiff_t col);
	~Matrix_R();
	Matrix_R& operator=(Matrix_R& z);
	Matrix_R& operator+=(Matrix_R& z);
	Matrix_R& operator*=(Matrix_R& z);

	std::ostream& writeTo(std::ostream& ostrm);

private:
	ptrdiff_t nRow_{ 0 };
	ptrdiff_t nCol_{ 0 };
	int** pRows_{ nullptr };
};

inline std::ostream& operator << (std::ostream& ostrm, Matrix_R& z)
{
	return z.writeTo(ostrm);
}
#endif