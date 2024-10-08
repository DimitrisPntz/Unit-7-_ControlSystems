#include "..\ActivationFunctions\ActivationFn.h"
#include "..\RNG\RNG.h"
#include "Neuron.h"


#include <string>
#include <utility>
#include <iostream>

Neuron::Neuron(int InputSize, std::string UCAF, float lr, float min, float max) : InputSize(InputSize), Weights(1, InputSize), ActivationFunction(UCAF), lr(lr){
    //Init Weights and biases
    bias = getRandomNumber(min, max);

    ActivFn = GetActivationFunction(UCAF);
}

void Neuron::info(){
    std::cout << "|-----------------NEURON INFO-----------------|" << std::endl;
    std::cout << "| Bias: " << bias << std::endl;
    std::cout << "| Learnable Parameters: " << Weights.GetCols() << std::endl;
    std::cout << "| Activation Function: " << ActivationFunction << std::endl;
    std::cout << "| Last Output: " << Output << std::endl;
    std::cout << "| Learning Rate: " << lr << std::endl;
    std::cout << "|---------------------------------------------|" << std::endl;
}