#include "Header.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector <double> arr = { 8,6,0,10 };
    std::cout << arithmeticMean(arr) << "\n";
    std::cout << median(arr) << "\n";
    std::cout << meanSquare(arr) << "\n";
    std::cout << variance(arr) << "\n";
}
