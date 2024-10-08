#ifndef MATRIX_H
#define MATRIX_H

#include "..\RNG\RNG.h"
#include <vector>

class Matrix{
    private:
        const int Rows;
        const int Cols;

        std::vector<float> Data;

    public:    
        //Default constructor
        Matrix(int Rows, int Cols) : Rows(Rows), Cols(Cols){
            Data.reserve(Rows * Cols);
        }

        //Random value constructor
        Matrix(int Rows, int Cols, float min, float max) : Rows(Rows), Cols(Cols){
            for(int i=0; i<Rows * Cols; i++){
                //Initialise the random  values in the matrix
                Data.push_back(getRandomNumber(min, max));

            }
        }

        //Previously defined array constructor
        Matrix(int Rows, int Cols, std::vector<float> Data) : Rows(Rows), Cols(Cols), Data(Data){}

        //General functions for the Matrix like getting values and Setting them 
        void Set(int Row, int Col, float Input);
        float Get(const int Row, const int Col);

        void PrintMatrix();

        //Get Rows/Cols
        float              GetRows(){return Rows;}
        float              GetCols(){return Cols;}
        std::vector<float> GetData(){return Data;}
};

float dotproduct(Matrix& a, Matrix& b, int Col, int Row);
Matrix matmul(Matrix& a, Matrix& b);
Matrix Hstack(Matrix& a, Matrix& b);
Matrix Vstack(Matrix& a, Matrix& b);
#endif