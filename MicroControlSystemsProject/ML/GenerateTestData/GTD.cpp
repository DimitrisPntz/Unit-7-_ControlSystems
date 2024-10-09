#include "GTD.h"
#include "..\RNG\RNG.h"

#include <vector>
#include <cmath>

std::vector<float> GenerateXvalues(int NoOfDataPoints, float noise, float min, float max){
    std::vector<float> X_Values;

    for(int i=0;i<NoOfDataPoints;i++){

        if(i % 2 == 0){X_Values.push_back(getRandomNumber(min + noise, max - noise));}
        else{X_Values.push_back(getRandomNumber(min - noise, max + noise));}
    }

    return X_Values;
}

std::vector<float> GenerateYvalues(float a, float b, float c, std::vector<float> X_values){
    std::vector<float> Y_values;

    for(int i=0;i<X_values.size();i++){
        float X = X_values[i];
        float Y_value = std::pow(X, 2) + b*X + c;

        Y_values.push_back(Y_value);
    }

    return Y_values;
}