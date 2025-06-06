#include "pch.h"
#include "MathLibrary.h"

double mean(const std::vector<double>& data) {
    if (data.empty()) return 0.0;
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

double median(std::vector<double> data) {
    if (data.empty()) return 0.0;
    std::sort(data.begin(), data.end());
    size_t size = data.size();
    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    }
    else {
        return data[size / 2];
    }
}

double rootMeanSquare(const std::vector<double>& data) {
    if (data.empty()) return 0.0;
    double sum = 0.0;
    for (double value : data) {
        sum += value * value;
    }
    return std::sqrt(sum / data.size());
}

double variance(const std::vector<double>& data) {
    if (data.empty()) return 0.0;
    double meanValue = mean(data);
    double sum = 0.0;
    for (double value : data) {
        sum += (value - meanValue) * (value - meanValue);
    }
    return sum / data.size();
}
