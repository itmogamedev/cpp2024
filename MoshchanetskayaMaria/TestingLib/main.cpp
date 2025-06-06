#include <iostream>
#include "..\MyStaticLib\statistics_lib.h"

int main() {
    std::vector<double> data = { 1.0, 2.0, 3.0, 4.0, 5.0 };

    std::cout << "Data: ";
    for (double value : data) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "Mean: " << Statistics::calculateMean(data) << std::endl;
    std::cout << "Median: " << Statistics::calculateMedian(data) << std::endl;
    std::cout << "Root Mean Square: " << Statistics::calculateRootMeanSquare(data) << std::endl;
    std::cout << "Variance: " << Statistics::calculateVariance(data) << std::endl;

    return 0;
//}