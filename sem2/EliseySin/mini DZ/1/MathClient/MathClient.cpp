#include <iostream>
#include <vector>
#include "MathLibrary.h"

int main() {
    std::vector<double> data = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
    int size = static_cast<int>(data.size());

    std::cout << "Mean: " << mean(data.data(), size) << std::endl;
    std::cout << "Median: " << median(data.data(), size) << std::endl;
    std::cout << "Root Mean Square: " << rootMeanSquare(data.data(), size) << std::endl;
    std::cout << "Variance: " << variance(data.data(), size) << std::endl;

    return 0;
}
