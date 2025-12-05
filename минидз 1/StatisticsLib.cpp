#include "StatisticsLib.h"
#include <algorithm>
#include <numeric>
#include <cmath>

double StatisticsLib::calculateMean(const std::vector<double>& data) {
    return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
}

double StatisticsLib::calculateMedian(std::vector<double> data) {
    std::sort(data.begin(), data.end());
    size_t size = data.size();
    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    }
    else {
        return data[size / 2];
    }
}

double StatisticsLib::calculateVariance(const std::vector<double>& data) {
    double mean = calculateMean(data);
    double sum = 0.0;
    for (double value : data) {
        sum += (value - mean) * (value - mean);
    }
    return sum / data.size(); // Дисперсия: делим на количество элементов
}

double StatisticsLib::calculateStdDev(const std::vector<double>& data) {
    return std::sqrt(calculateVariance(data)); // Среднее квадратическое: корень из дисперсии
}