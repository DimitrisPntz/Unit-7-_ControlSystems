#pragma once

#include "..\Neuron\Neuron.h"

#include <vector>
#include <string>

class Dense{
    private:
        const int NoOfNeurons;
        const int NoOfInputs;

        std::vector<Neuron> Layer;

        std::string ActivationFunction;
    
    public:
        //Constructor for dense class
        Dense(int NoOfNeurons, int NoOfInputs, std::string UCAF, float min=-1.0f, float max=1.0f);

        //General info for the layer
        void info();

        //Forward pass
        Matrix forward(Matrix& Input);

        //Softmax and Argmax if needed
        Matrix Softmax();
        int Argmax();
        float GetSoftmaxValue(int Class);
};
