#pragma once

#include <cmath>
#include <string>

typedef float (*ActivPntr)(float);

ActivPntr GetActivationFunction(const std::string& name);
