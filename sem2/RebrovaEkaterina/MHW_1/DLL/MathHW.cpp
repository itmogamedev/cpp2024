#include "pch.h"
#include "MathHW.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

// Функция для подсчета среднего арифметического
double calculateMean(const std::vector<double> data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

// Функция для подсчета медианы
double calculateMedian(std::vector<double> data) {
    std::sort(data.begin(), data.end());
    size_t size = data.size();
    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    }
    else {
        return data[size / 2];
    }
}

// Функция для подсчета среднего квадратического
double calculateRootMeanSquare(const std::vector<double> data) {
    double sum = 0.0;
    for (double value : data) {
        sum += value * value;
    }
    return std::sqrt(sum / data.size());
}

// Функция для подсчета дисперсии
double calculateVariance(const std::vector<double> data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    double mean = sum / data.size();
    sum = 0.0;
    for (double value : data) {
        sum += (value - mean) * (value - mean);
    }
    return sum / data.size();
}