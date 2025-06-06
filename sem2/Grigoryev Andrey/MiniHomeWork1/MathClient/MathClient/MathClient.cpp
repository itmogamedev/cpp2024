#include <iostream>
#include "MathLibrary.h"
#include <vector>

int main()
{
    std::vector<double> a = {8, 6, 0, 10};
    std::cout << "Average: ";
    std::cout << average(a) << std::endl;
    std::cout << "Median: ";
    std::cout << median(a) << std::endl;
    std::cout << "Square average: ";
    std::cout << square_average(a) << std::endl;
    std::cout << "Variance: ";
    std::cout << variance(a) << std::endl;
}