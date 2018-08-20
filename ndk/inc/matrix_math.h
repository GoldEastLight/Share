
#ifndef MATRIX_MATH
#define MATRIX_MATH

#include <stdio.h>
#include <stdlib.h>
//#include <memory.h>
#include <assert.h>
#include <math.h>
#include "string.h"

#ifdef   __cplusplus   
extern   "C"   
{   
#endif 

/** \brief Strassen matrix inversion.
*
*	This is a matrix inversion algorithm invented by Strassen. It is fast, but the implementation only works, it the number of rows is equal to 
*	$2^n$. The algorithm is taken from Wikipedia. Beware, that this algorithm is not ultimately numerical stable.
*
*  \param[in]  **src  Pointer to the source matrix.
*  \param[out] **res  Pointer to the result matrix.
*  \param[in] numberOfRows	Number of rows of the source and the result matrix.
*  \param[in] numberOfColumns	Number of columns of the source and the result matrix. 
*/
void matInvert(const float **src, float **res, short numberOfRows, short numberOfColumns);

/** \brief Cholesky decomposition of a matrix.
*
*	This function decomposes a matrix using the cholesky algorithm. The algorithm is for example used to calculate the square root of a positive semidefinite matrix.
*	The implementation is taken from numerical recipes and was adapted to the structure used in our matrix functions. 
*
*  \param[in,out]	src					Pointer to the source matrix. The result will also be written to this matrix.
*  \param[in]		srcNumberOfRows		Number of rows and columns of the source matrix.
*/
void choleskyDecomposition(float **src, short srcNumberOfRowsCols);


/** \brief Jacobi transformation of a matrix.
*
*	The function is the implementation of a jacobi transformation of a matrix adjusted for the used matrix structures. The code is currently not active.
*
*  \param[in,out]  **symMat		Pointer to the source matrix. The result will also be written to this matrix.
*  \param[in] *tempVec1			A vector for temporary data. The length of the vector is given by size. 
*  \param[in] *tempVec2			A vector for temporary data. The length of the vector is given by size.
*  \param[out] **d				D matrix. Have a look into numerical recipes.
*  \param[out] **v				V matrix. Have a look into numerical recipes.
*  \param[in]  size				number of columns and rows of the D and V matrix and the number of rows of the temporary vectors.
*  \return						The number of iterations needed.
*/
int jacobiTrans(float **symMat, float* tempVec1, float* tempVec2, float **d, float **v, short size);

/** \brief Singular value decomposition.
*
*	The code performs a singular value decomposition on matrix A: $A=U*W*V^T$
*	The code was taken from numerical recipes and adjusted for our purposes.
*
*  \param[in]  **a		Pointer to the matrix that should be decomposed.
*  \param[in] m			Number of rows of a.
*  \param[in] n			Number of columns of a.
*  \param[in] *rv1		Pointer to a temporary vector of length n.
*  \param[out] **u		First matrix of the decomposition of size m * n.
*  \param[out] **v      Second matrix of the decomposition of size n * n.
*  \param[out] *w		Diagonal of matrix w given as a vector of size n.
*/
void svdCmp(float **a, short m, short n, float** u, float** v, float *w, float *temp);

/** \brief Calculates an MMSE estimate.
*
*	Solves $A·X = B$ or the solution that calculates an X minimizing the error vector given by $r=A*X-B$. The function applies a singular value decomposition.
*  \param[in] **mat		Pointer to matrix A of size m * n.
*  \param[in] *eqB		Pointer to vector B of size n.
*  \param[in] *eqX		Pointer to vector X of size n.
*  \param[in] **u		Temporary matrix having m rows and n columns.
*  \param[in] **v       Temporary matrix having n rows and n columns.
*  \param[in] **w		Temporary matrix having 2 rows and n columns.
*  \param[in] matRows   Rows of matrix mat (m).
*  \param[in] matColumns Columns of matrix mat (n).
*/
void calcMMSEEstimate(float** mat, float* eqB, float* eqX, float** u, float** v, float** w, short matRows, short matColumns);


/*! \brief Creates a matrix object.
*
*   The function creates a float matrix with the given number of rows and number or columns. Use it with care, because there is no boundary check in matrix functions.
*
*	\param[in] numberOfRows    number of rows in the tracker
*	\param[in] numberOfColumns number of columns in the tracker
*	\return A pointer to the created matrix
*/
float** matInit(short numberOfRows, short numberOfColumns);


/*! \brief Creates a numerical recipes compatible object.
*	
*	The function creates a matrix for numerical recipes functions. However, the algorithms on this side do not work with the resulting matrix.
*
*	\param[in] numberOfRows    number of rows in the tracker
*	\param[in] numberOfColumns number of columns in the tracker
*	\return A pointer to the created matrix. It is addressable from 1..numberOfRows and 1...numberOfColumns.
*/
float** matNumRecInit(short numberOfRows, short numberOfColumns);


/*!	\brief Creates a matrix interface for the subregion of another existing matrix. 
*
*	The function creates pointer array that allows to address the elements of a subregion of another existing matrix as if they were a seperate new matrix.
*	
*	\param[in,out] srcMat The source matrix. The resulting pointers point to elements in this matrix.
*	\param[in] startRow first row to address with the new matrix
*	\param[in] endRow last row to address by the new matrix
*	\param[in] startColumn first column to address by the new matrix
*	\param[in] endColumn last column to address by the new matrix
*	\return A pointer to the created matrix. The matrix can be addressed in the range of 0..endRow-startRow and 0..endColumn-startColumn.
*/
float** matAllocSubMatArea(float** srcMat, short startRow, short endRow, short startColumn, short endColumn);


/*!	\brief Creates a matrix interface for the subregion of another existing matrix using a const pointer.
*	
*	The function creates a matrix that allows to address the elements of a subregion of another existing matrix. This function differs from the one above that it creates a const pointer that prohibits to change the elements.
*
*	\param[in,out] srcMat The source matrix. The resulting pointers point to elements in this matrix.
*	\param[in] startRow first row to address with the new matrix
*	\param[in] endRow last row to address by the new matrix
*	\param[in] startColumn first column to address by the new matrix
*	\param[in] endColumn last column to address by the new matrix
*	\return A pointer to the created matrix
*/
const float** matAllocConstSubMatArea(const float** srcMat, short startRow, short endRow, short startColumn, short endColumn);


/*! \brief  Destroys a matrix.
*	
*	The function deallocates the memory needed for a matrix.
*	
*	\param[in] matrix The matrix that shall be deleted.
*/
void matCleanup(float** matrix);


/*! \brief  Destroys a const matrix.
*	
*	The function deallocates the memory needed for a matrix. The function can be used for const pointers.
*
*	\param[in,out] matrix The matrix that shall be deleted.
*/
void matConstCleanup(const float** matrix);


/*! \brief The function copies the content of a matrix or a submatrix to the target matrix.
*
*	The function copies the content of a matrix or a subregion of a matrix to another matrix.
*
*	The content of pSrc at startRow...endRow and startColumn..endColumn is writen to the target at row 0...endRow-startRow and column 0..endCol-startCol.
*	\param[in]		pSrc		The matrix from which the region is taken.
*	\param[in,out]	pRes		The matrix to which the content of the source matrix should be copied.
*	\param[in]		startRow	The first row to copy to the target
*	\param[in]		endRow		The last row that has to be be copied
*	\param[in]		startColumn The first column that has to be copied
*	\param[in]		endColumn	The last column that has to be copied
*/
void extractSubMat(const float** pSrc, float** pRes, short startRow, short endRow, short startColumn, short endColumn);


/*! \brief The function copies the content of one matrix into another matrix of the same dimension.
*
*	The function copies the content of one matrix into another matrix of the same dimension. If the matrix dimensions are not equal, the operation may fail.
*
*	\param[in]		pSrc		The matrix from which the region is taken.
*	\param[out]		pRes		The matrix to which the content of the source matrix should be copied.
*	\param[in]		rows		The number of rows of the matrix.
*	\param[in]		columns		The number of columns of the matrix.
*/
void matCopy(float** pRes, const float** pSrc, short rows, short columns);


/*! \brief Sets all elements in a matrix to zero.
*
*	The function the content of an existing matrix to zero. The size should be identical to the size of the matrix.
*
*	\param[out] pSrc The matrix that has to be resetted.
*	\param[in] numberOfRows The first column that has to be copied.
*	\param[in] numberOfColumns The last column that has to be copied.
*/
void matReset(float **pSrc, short numberOfRows, short numberOfColumns);


void matReset_I(int** pSrc, short numberOfRows, short numberOfColumns);


/*!  \brief Matrix multiplication.
*
*	The function multiplies two matrices. The target pointer and the source pointers have to be different. The resulting matrix has a dimension of src1NumberOfColumns and src2NumberOfRows.
*
*	\param[in] pSrc1 The first source matrix.
*	\param[in] pSrc2 The second source matrix.
*	\param[out] pResult The pointer to the resulting matrix.
*	\param[in] src1NumberOfRows number of rows of source matrix 1.
*	\param[in] src1NumberOfColumns number of columns of source matrix 1.
*	\param[in] src2NumberOfRows number of rows of source matrix 2.
*	\param[in] src2NumberOfColumns number of columns of source matrix 2.
*/
void matMult(const float** pSrc1, const float** pSrc2, float** pResult, short src1NumberOfRows, short src1NumberOfColumns, short src2NumberOfRows, short src2NumberOfColumns);


void matMult_I(const int** pSrc1, const int** pSrc2, int** pResult, short src1NumberOfRows, short src1NumberOfColumns, short src2NumberOfRows, short src2NumberOfColumns);

/*!  \brief Hilbert Schmidt norm of a matrix.
*
*	 The function calculates the Hilbert Schmidt norm of a matrix. 
*	
*	/param[in] src The matrix.
*	/param[in] srcNumberOfRows number of rows of the source matrix.
*	/param[in] srcNumberOfColumns number of columns of the source matrix.
*/
float matHilbertSchmidtNorm(const float** src, short srcNumberOfRows, short srcNumberOfColumns);


/*! \brief Multiplication of a matrix with a scalar.
*	
*	The function multiplies a matrix with a scalar. It is possible to pass the same address as src and dest ptr. Otherwise, it is required that the source and the destination matrix have the same dimensions.
*
*	/param[in]  scalar The scalar value.
*	/param[in]  src The matrix.
*	/param[out] dest The pointer to the matrix, to which the result should be written.
*	/param[in] srcNumberOfRows number of rows of source matrix 1.
*	/param[in] srcNumberOfColumns number of columns of source matrix 1.
*/
void matMultScalar(float scalar, const float** src, float **dest, short srcNumberOfRows, short srcNumberOfColumns);


/*! \brief Matrix addition.
*
*	The function adds two matrices having the same dimensions. It is possible to pass the same matrix as one of the source matrices and as target matrix. 
*
*	\param[in]  pSrc1 A pointer to the first source matrix.
*	\param[in]  pSrc2 A pointer to the second source matrix.
*	\param[out] pResult The result will be written to this matrix.
*	\param[in]  src1NumberOfRows number of rows of the source matrices and the result matrix.
*	\param[in]  src1NumberOfColumns number of columns of the source matrices and the result matrix.
*	\param[in]  src2NumberOfRows number of rows of the source matrices and the result matrix.
*	\param[in]  src2NumberOfColumns number of columns of the source matrices and the result matrix.
*/
void matAdd(const float** pSrc1, const float** pSrc2, float** pResult, short src1NumberOfRows, short src1NumberOfColumns, short src2NumberOfRows, short src2NumberOfColumns);


/*! \brief Matrix subtraction.
*
*	The function subtracts matrix 2 from matrix 1. The source matrices and the target matrix should have the same dimensions.
*	It is possible to pass the same matrix as one of the source matrices and as target matrix. 
*	\param[in]  pSrc1 A pointer to the first source matrix.
*	\param[in]  pSrc2 A pointer to the second source matrix.
*	\param[out] pResult The result will be written to this matrix.
*	\param[in]  src1NumberOfRows number of rows of the source matrices and the result matrix.
*	\param[in]  src1NumberOfColumns number of columns of the source matrices and the result matrix.
*	\param[in]  src2NumberOfRows number of rows of the source matrices and the result matrix.
*	\param[in]  src2NumberOfColumns number of columns of the source matrices and the result matrix.
*/
void matSub(const float** pSrc1, const float** pSrc2, float** pResult, short src1NumberOfRows, short src1NumberOfColumns, short src2NumberOfRows, short src2NumberOfColumns);


/*! \brief Calulates the determinant of a 2x2 matrix.
*
*	\param[in]  src   A pointer to the 2x2 source matrix
*	\return		      the determinant
*/
float det2x2(const float** src);


/*! \brief Calulates the determinant of a 3x3 matrix.
*
*	\param[in]  src   A pointer to the 3x3 source matrix
*	\return		      the determinant
*/
 float det3x3(const float** src);


/*! \brief Matrix print.
*
*	The function prints the content of a matrix in a nice formatted way ;-).
*
*	\param[in]  pSrc A pointer to matrix to plot.
*	\param[in]  numberOfRows number of rows of the source matrices and the result matrix.
*	\param[in]  numberOfColumns number of columns of the source matrices and the result matrix.
*/
void matPrint(const float** pSrc, short numberOfRows, short numberOfColumns);


/*! \brief Matrix transpose.
*	
*	The function transposes a matrix.
*
*	\param[in]  pSrc A pointer to the source matrix.
*	\param[in]  pRes A pointer to the result matrix.
*	\param[in]  srcNumberOfRows The number of rows in the source matrix.
*	\param[in]  srcNumberOfColumns The number of columns in the source matrix.
*/
void matTransp(const float** pSrc, float** pRes, short srcNumberOfRows, short srcNumberOfColumns);


/* ------------------------------------------------------- */
/*! \brief Matrix inversion using SVD
*
*	This function computes the inverse of a square matrix of arbitrary size. 
*
*	\param[in]  pSrc	A pointer to the source matrix.
*	\param[in]  tempU	A pointer to a temporary square matrix of the same size as pSrc.
*	\param[in]  tempV   A pointer to a temporary square matrix of the same size as pSrc.
*	\param[in]  tempW	A pointer to a temporary vector with length equal to the size of pSrc.
*	\param[in]  tempW2	A pointer to a temporary vector with length equal to the size of pSrc.
*	\param[out] pRes	A pointer to a square matrix of same size as pSrc. The result will be stored here.
*	\param[in]  numberOfRows	Size of matrix pSrc.
*/
void matInvertSVD(const float **pSrc, float **pRes, float **tempU,float **tempV, float *tempW, float *temp2,int numberOfRows);

#ifdef   __cplusplus   
}  
#endif

#endif MATRIX_MATH