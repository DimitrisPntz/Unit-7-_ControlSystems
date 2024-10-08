#pragma once

#include "..\Matrix\Matrix.h"
#include "..\ActivationFunctions\ActivationFn.h"

#include <string>

class Neuron{
    private:
        //General Info for the AI
        const int InputSize;
        float Output = 0.0f;

        //Weights, bias and lr
        Matrix Weights;
        float bias;
        float lr;

        //Activation functions
        ActivPntr ActivFn; 

        std::string ActivationFunction;

    public:
        Neuron(int InputSize, const std::string ActivFn, float lr=0.01, float min=-1.0f, float max=1.0f);

        //Neuron Info
        void info();

        //Forward Pass
        float forward(Matrix& Inputs){Output = ActivFn(matmul(Weights, Inputs).Get(0, 0) + bias); return Output;}

        //IMPLEMENT THE BACKWARDS PASS
};
