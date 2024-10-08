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

    a.PrintMatrix();
    Matrix d(1, 5, -1.0f, 1.0f);
    d.PrintMatrix();

    //Vstack
    std::cout << "Vstack: " <<std::endl;
    
    Matrix Vstack1(2, 3, -1.0f, 1.0f);
    Vstack1.PrintMatrix();

    Matrix Vstack2(2, 3, -1.0f, 1.0f);
    Vstack2.PrintMatrix();

    Matrix e = Vstack(Vstack1, Vstack2);
    e.PrintMatrix();

    //Hstack
    std::cout << "Hstack: " <<std::endl;

    Matrix Hstack1(2, 3, -1.0f, 1.0f);
    Hstack1.PrintMatrix();

    Matrix Hstack2(2, 3, -1.0f, 1.0f);
    Hstack2.PrintMatrix();

    Matrix f = Hstack(Hstack1, Hstack2);
    f.PrintMatrix();
}

//g++ main.cpp ML/ActivationFunctions/Activation.cpp ML/Matrix/Matrix.cpp ML/Neuron/Neuron.cpp ML/RNG/RNG.cpp