#include "LossFunctions.h"

#include <cmath>
#include <string>
#include <stdexcept>

typedef float (*LossPntr)(float, float);

float SE(float Observed, float Predicted){
    return std::pow((Observed - Predicted), 2);
}

float AE(float Observed, float Predicted){
    return std::abs((Observed - Predicted));
}

float BCEL(float Observed, float Predicted){
    return Observed * std::log(Predicted) + (1 - Observed) * std::log(1 - Predicted);
}

LossPntr GetLossFunctionPtr(const std::string UCLF)
{
	//UCLF just means User Chosen Loss Function, now just return the ptr to the activation function
	if(UCLF == "se")
	{
		return &SE;
	} else if (UCLF == "mae") 
	{
		return &AE;
	}else if (UCLF == "bcel"){
        return &BCEL;
    }

	throw std::invalid_argument("Activation function was not chosen.");
}