#include "..\Neuron\Neuron.h"
#include "Layers.h"

#include <string>
#include <iostream>
#include <cmath>
#include <stdexcept>

//THIS FILE ALSO CONTAINS ARGMAX!!!!

Matrix Dense::Softmax(){
    //Calculate the denominator for softmax
    float Denominator = 0.0f;

    std::vector<float> NeuronOutputs;

    for(int i=0;i<NoOfNeurons;i++){
        float NeuronOutput = std::exp(Layer[i].GetOutput());

        //Add it both to the denominator and to the vector to not waste time computing it again
        NeuronOutputs.push_back(NeuronOutput);
        Denominator += NeuronOutput;
    }

    //init Output matrix
    Matrix SoftmaxOutput(NoOfNeurons, 1);

    for(int i=0;i<NoOfNeurons;i++){
        //Calculate the individual Neurons softmax
        SoftmaxOutput.Set(i, 0, (NeuronOutputs[i] / Denominator));
    }

    return SoftmaxOutput;
}

float Dense::GetSoftmaxValue(int Class){
    if(Class < 0 || Class > NoOfNeurons){
        throw std::domain_error("Class does not exist in this layer! ");
    }

    float Denominator = 0.0f;

    std::vector<float> NeuronOutputs;

    for(int i=0;i<NoOfNeurons;i++){
        float NeuronOutput = std::exp(Layer[i].GetOutput());

        //Add it both to the denominator and to the vector to not waste time computing it again
        NeuronOutputs.push_back(NeuronOutput);
        Denominator += NeuronOutput;
    }

    return NeuronOutputs[Class] / Denominator;
}

int Dense::Argmax(){
    //Calculate the denominator for softmax
    float Denominator = 0.0f;

    std::vector<float> NeuronOutputs;

    for(int i=0;i<NoOfNeurons;i++){
        float NeuronOutput = std::exp(Layer[i].GetOutput());

        //Add it both to the denominator and to the vector to not waste time computing it again
        NeuronOutputs.push_back(NeuronOutput);
        Denominator += NeuronOutput;
    }

    int Class = -1;
    float BestScore = -99999.9f;

    for(int i=0;i<NoOfNeurons;i++){

        //Calculate the individual Neurons softmax
        float NeuronScore = NeuronOutputs[i] / Denominator;

        if((NeuronScore) > BestScore){
            Class = i;
            BestScore = NeuronScore;
        };
    }

    return Class;
}
