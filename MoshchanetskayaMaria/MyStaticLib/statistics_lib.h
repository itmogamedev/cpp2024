#pragma once
#ifndef STATISTICS_LIB_H
#define STATISTICS_LIB_H

#include <vector>
#include <cmath>
#include <algorithm>

namespace Statistics {

    double calculateMean(const std::vector<double>& data);

    double calculateMedian(std::vector<double> data);

    double calculateRootMeanSquare(const std::vector<double>& data);

    double calculateVariance(const std::vector<double>& data);

} 
#endif // STATISTICS_LIB_H
