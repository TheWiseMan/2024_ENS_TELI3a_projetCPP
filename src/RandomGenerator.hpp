#include <random>
class RandomGenerator
{
private:
    std::mt19937 gen;                     // Mersenne Twister engine
    std::uniform_real_distribution<> dis; // Uniform distribution [0.0, 1.0)

public:
    // Constructor initializes the generator and distribution
    RandomGenerator()
        : gen(std::random_device{}()), // Seed the engine
          dis(0.0, 1.0)                // Set range [0, 1)
    {
    }

    // Method to generate a random double in the range [0, 1)
    float getRandom();
};