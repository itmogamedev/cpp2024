#include <iostream>
#include <vector>
#include "MathLibrary.h"

int main()
{   
    std::vector<float> numbers = { 1.1, 2.2, 3.3, 5.5, 6.6 };

    std::cout << "Average: " << average(numbers) << "\n";
    std::cout << "AverageSQRT: " << averagesqrt(numbers) << "\n";
    std::cout << "Median: " << median(numbers) << "\n";
    std::cout << "Dispersion: " << dispersion(numbers) << "\n";
}