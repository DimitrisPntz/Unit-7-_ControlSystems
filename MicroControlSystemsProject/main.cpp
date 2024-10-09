#include "ML\Matrix\Matrix.h"
#include "ML\Neuron\Neuron.h"
#include "ML\Layers\Layers.h"

#include "ML\GenerateTestData\GTD.h"
#include "ML\LossFunctions\LossFunctions.h"

#include <iostream>
#include <cmath>

int main(){
    std::vector<float> X_Values = GenerateXvalues(20, 0.1f, -10.0f, 10.0f);
    std::vector<float> Y_Values = GenerateYvalues(2.0f, 3.0f, 13.0f, X_Values);

    LossPntr LossFunction = GetLossFunctionPtr("se");

    int NOEPOCHS = 100;

    //initialise weights and biases
    float a = getRandomNumber(-1.0f, 1.0f);
    float b = getRandomNumber(-1.0f, 1.0f);
    float c = getRandomNumber(-1.0f, 1.0f);

    std::cout << "a " << a << std::endl;
    std::cout << "b " << b << std::endl;
    std::cout << "c" << c << std::endl;

    float lr = 0.00005f;

    for(int i=0;i<NOEPOCHS;i++){
        
        float SE = 0.0f;

        //Get the Squared Error of all the training examples
        for(int j=0;j<X_Values.size();j++){
            float X = X_Values[j];
            float Y = Y_Values[j];

            float y_hat = a * std::pow(X, 2) + b * X + c;

            SE += LossFunction(Y, y_hat);
        }

        float MSE = (1.0f / static_cast<float>(X_Values.size())) * SE;

        std::cout << "Epoch " << i << " MSE: " << MSE << std::endl;

        float dMSE = (-2.0f / static_cast<float>(X_Values.size())) * SE;

        //update weights 
        a = a -lr * (a * dMSE);
        std::cout << "a " << a << std::endl;

        b = b -lr * (b * dMSE);
        std::cout << "b " << b << std::endl;

        c = c -lr * (c * dMSE);
        std::cout << "c " << c << std::endl;
    }
}

//g++ main.cpp ML/ActivationFunctions/Activation.cpp ML/Matrix/Matrix.cpp ML/Neuron/Neuron.cpp ML/RNG/RNG.cpp ML/Layers/Dense.cpp ML/Layers/Softmax.cpp
