

#include <iostream>
#include "MathHW.h"
#include <vector>
#include <string>

int main()
{
    std::vector <double> a = { 1, 4, 3, 4 };
    std::cout << calculateMean(a) << std::endl;
    std::cout << calculateMedian(a) << std::endl;
    std::cout << calculateRootMeanSquare(a) << std::endl;
    std::cout << calculateVariance(a) << std::endl;
}

