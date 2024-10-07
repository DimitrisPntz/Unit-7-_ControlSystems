#include "RNG.h"
#include <random>

float getRandomNumber(float min, float max) {
    static std::random_device rd; // Obtain a random number from hardware
    static std::mt19937 eng(rd()); // Seed the generator
    std::uniform_real_distribution<float> distr(min, max); // Define the range
    return distr(eng); // Generate a random number
}