#include "ActivationFn.h"

#include <cmath>
#include <string>
#include <stdexcept>
#include <utility>

typedef float (*ActivPntr)(float);

float Sigmoid(float x) {
    return 1.0f / (1.0f + std::exp(-x));
}

// float SigmoidDerivative(float x) {
//     float sig = Sigmoid(x);
//     return sig * (1.0f - sig);
// }

float Tanh(float x) {
    return std::tanh(x);
}

// float TanhDerivative(float x) {
//     float tanh_x = Tanh(x);
//     return 1.0f - tanh_x * tanh_x;
// }

float ReLU(float x) {
    return (x > 0) ? x : 0.0f;
}

// float ReLUDerivative(float x) {
//     return (x > 0) ? 1.0f : 0.0f;
// }

float LeakyReLU(float x) {
    return (x > 0) ? x : 0.01f * x;
}

// float LeakyReLUDerivative(float x) {
//     return (x > 0) ? 1.0f : 0.01f;
// }

float ClippedReLU(float x) {
    if (x >= 1)     {return 1.0f;} //1 is the max 
    else if (x <= 0){return 0.0f;} //0 is the min

    return x;
}

// float ClippedReLUDerivative(float x) {
//     return (x > 0 && x < 1) ? 1.0f : 0.0f;
// }

ActivPntr GetActivationFunction(const std::string& name) {
    if (name == "sigmoid") {
        return &Sigmoid;
    } else if (name == "relu") {
        return &ReLU;
    } else if (name == "leakyrelu") {
        return &LeakyReLU;
    } else if (name == "tanh") {
        return &Tanh;
    } else if (name == "clippedrelu") {
        return &ClippedReLU;
    } else {
        throw std::invalid_argument("Unknown activation function");
    }
}
