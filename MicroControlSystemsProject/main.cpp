#include "ML\Matrix\Matrix.h"
#include "ML\Neuron\Neuron.h"

#include <iostream>

int main(){
    Matrix a(1, 5, -1.0f, 1.0f);
    a.PrintMatrix();

    Matrix b(5, 1, -1.0f, 1.0f);
    b.PrintMatrix();

    Matrix c = matmul(a, b);
    c.PrintMatrix();

    Neuron First(5, "relu");

    float output = First.forward(b);
    std::cout << "Forward Pass: " << output << std::endl;

    First.info();
}