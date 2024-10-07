#include "ML\Matrix\Matrix.h"

int main(){
    Matrix a(1, 5, -1.0f, 1.0f);

    a.PrintMatrix();
    
    Matrix b(5, 1, -1.0f, 1.0f);

    b.PrintMatrix();

    Matrix c = matmul(a, b);

    c.PrintMatrix();
}