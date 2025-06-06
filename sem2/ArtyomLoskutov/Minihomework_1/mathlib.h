#pragma once
#include <vector>

namespace MathLibrary
{
    class Arithmetic
    {
    public:
        static double mid(std::vector<int> numbers);
        static double med(std::vector<int> numbers);
        static double midsqrt(std::vector<int> numbers);
        static double disp(std::vector<int> numbers);
    };
}