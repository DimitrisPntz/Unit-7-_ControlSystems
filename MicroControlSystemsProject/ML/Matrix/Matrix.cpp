#include "Matrix.h"
#include <iostream>

float Matrix::Get(const int Row, const int Col)
{
	//Guard Clause: prevents user from trying to access indexes in the Matrix that do not exist.
	if (Row >= Rows || Col >= Cols || Row < 0 || Col < 0) {
		throw std::out_of_range("Row and Column you are trying to access does not exist in this matrix.");
	}

	return Data[Row * Cols + Col];
}

void Matrix::Set(const int Row, const int Col, float Input)
{
	if (Row >= Rows || Col >= Cols || Row < 0 || Col < 0) {
		throw std::out_of_range("Row and Column you are trying to access does not exist in this matrix.");
	}
	
	Data[Row * Cols + Col] = Input;
}

void Matrix::PrintMatrix() {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            std::cout << Get(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

float dotproduct(Matrix& a, Matrix& b, int Col, int Row){
    float dotproduct = 0;

    //Calculate the dot product
    for (int k = 0; k < a.GetCols(); k++) {
        dotproduct += a.Get(Col, k) * b.Get(k, Row);
    }

    return dotproduct;
}

Matrix matmul(Matrix& a, Matrix& b) {
	if (a.GetCols() != b.GetRows()) 
	{
		throw std::domain_error("Matrix A's columns do not equal to Matrix B's rows. So they cannot be multiplied");
	}

    Matrix ResultingMatrix(a.GetRows(), b.GetCols());

    for (int Col=0; Col<b.GetCols(); Col++) 
    {
        for (int Row=0; Row<a.GetRows(); Row++)
        {
            ResultingMatrix.Set(Col, Row, dotproduct(a, b, Col, Row));
        }
    }
    
    return ResultingMatrix;
}