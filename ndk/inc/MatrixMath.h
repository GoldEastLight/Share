

#ifndef _MATRIX_MATH_
#define _MATRIX_MATH_


void mat_mult(const float** pSrc1, const float** pSrc2, float** pResult, short src1NumberOfRows, short src1NumberOfColumns, short src2NumberOfRows, short src2NumberOfColumns);
float** mat_init(short numberOfRows, short numberOfColumns);
void mat_add(const float** pSrc1, const float** pSrc2, float** pResult, short src1NumberOfRows, short src1NumberOfColumns, short src2NumberOfRows, short src2NumberOfColumns);
void mat_sub(const float** pSrc1, const float** pSrc2, float** pResult, short src1NumberOfRows, short src1NumberOfColumns, short src2NumberOfRows, short src2NumberOfColumns);

#endif