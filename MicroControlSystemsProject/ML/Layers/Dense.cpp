#include "..\Neuron\Neuron.h"
#include "Layers.h"

#include <string>
#include <iostream>

Dense::Dense(int NoOfNeurons, int NoOfInputs, std::string UCAF, float min, float max) : NoOfNeurons(NoOfNeurons), NoOfInputs(NoOfInputs), ActivationFunction(UCAF){
    for(int i=0;i<NoOfNeurons;i++){
        Layer.emplace_back(NoOfInputs, UCAF);
    }
}

void Dense::info(){
    std::cout << "|-----------------LAYER INFO-----------------|" << std::endl;
    std::cout << "| Number of Neurons in Layer: " << NoOfNeurons << std::endl;
    std::cout << "| Number of Inputs to each Neuron: " << NoOfInputs << std::endl;
    std::cout << "| Learnable Parameters: " << NoOfNeurons * NoOfInputs + NoOfNeurons << std::endl;
    std::cout << "| Activation Function: " << ActivationFunction << std::endl;
    std::cout << "| Type of Layer: Dense" << std::endl;
    std::cout << "|---------------------------------------------|" << std::endl;
}

Matrix Dense::forward(Matrix& Input){
    Matrix ResultingMatrix(NoOfNeurons, 1);

    for(int i=0;i<NoOfNeurons;i++){
        float NeuronOutput = Layer[i].forward(Input);        
        ResultingMatrix.Set(i, 0, NeuronOutput);
    }

    return ResultingMatrix;
}