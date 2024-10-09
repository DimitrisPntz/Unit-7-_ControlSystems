#pragma once

#include <cmath>
#include <string>

typedef float (*LossPntr)(float, float);

LossPntr GetLossFunctionPtr(const std::string UCLF);