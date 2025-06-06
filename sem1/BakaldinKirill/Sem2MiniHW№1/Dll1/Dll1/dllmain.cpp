// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "Header.h"


double arithmeticMean(const std::vector<double>& data) {
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

double meanSquare(const std::vector<double>& data) {
    if (data.empty()) return 0.0;
    double sum = 0.0;
    for (double value : data) {
        sum += value * value;
    }
    return std::sqrt(sum / data.size());
}

double variance(const std::vector<double>& data) {
    if (data.empty()) return 0.0;
    double mean = arithmeticMean(data);
    double sum = 0.0;
    for (double value : data) {
        sum += (value - mean) * (value - mean);
    }
    return sum / data.size();
}
