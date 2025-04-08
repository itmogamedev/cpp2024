#include "Randomizer.h"

float Random::bitRandom()
{
    return intRandom(0, 10000) / 10000.0f;
}

int Random::intRandom(int left, int right)
{
    if (left > right)
        throw "Logic_error";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(left, right);
    return dist(gen);
}
