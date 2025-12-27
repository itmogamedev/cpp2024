#include <iostream>
#include "AlgebraLibrary.h"
#include <vector>

int main()
{
    std::vector<double> nums = RandomInit(10);
    WriteVector(nums);
    std::cout << ArithmetiсMean(nums) << std::endl;
    std::cout << Median(nums) << std::endl;
    std::cout << SquareMean(nums) << std::endl;
    std::cout << Dispersion(nums) << std::endl;
    GeneralStats(nums);
}
