
#include <vector>
#include <iostream>
#include "MYDLL.h"


int main()
{
    std::vector <float> a = { 2.2, 5.1, 0.0, 2.75, 10.33, 13.2 };
    std::cout << "average arithmetic: " << average_Arithmetic(a) << "\n";
    std::cout << "median: "<< median(a) << "\n";
    std::cout << "average_square: " << average_square(a) << "\n";
    std::cout << "dispersion: " << dispersion(a) << "\n";
}