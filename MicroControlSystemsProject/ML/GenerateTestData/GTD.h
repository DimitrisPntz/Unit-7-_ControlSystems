#pragma once

#include <vector>

std::vector<float> GenerateXvalues(int NoOfDataPoints, float noise, float min, float max);

std::vector<float> GenerateYvalues(float a, float b, float c, std::vector<float> X_values);