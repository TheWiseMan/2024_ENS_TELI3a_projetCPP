#include "RandomGenerator.hpp"

float RandomGenerator::getRandom()
{
    return dis(gen);
}