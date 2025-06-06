#include <iostream>
#include <vector>
#include "../include/libStatistics.h"


int main() {

    std::vector<long long> vec{2, 4, 4, 5, 5, 7, 9};
    std::cout << "Mean: " << calculateMean(vec) << '\n';
    std::cout << "RMS: " << calculateRMS(vec) << '\n';
    std::cout << "Median: " << calculateMedian(vec) << '\n';
    std::cout << "Variance: " << calculateVariance(vec) << '\n';
    return 0;
}
