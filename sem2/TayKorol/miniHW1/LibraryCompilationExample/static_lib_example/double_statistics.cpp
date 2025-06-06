#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

double calculateMean(const std::vector<double> &values) {
    if (values.empty()) {
        throw std::invalid_argument("The input vector must not be empty.");
    }

    double current_average = values.at(0);
    for (size_t i = 1; i < values.size(); ++i) { //  метод Уэлфорда //
        current_average += ((values.at(i)) - current_average) / (i + 1); // Potential Overflow
    }
    return current_average;
}


double calculateMedian(std::vector<double> values) {
    if (values.empty()) {
        throw std::invalid_argument("The input vector must not be empty.");
    }

    std::sort(values.begin(), values.end());

    size_t size = values.size();
    size_t middle = size / 2;

    if (size % 2 != 0) {
        return (values[middle]);
    } else {
        return ((values[middle - 1]) + (values[middle])) / 2.0;
        // Potential Overflow
    }
}


double calculateRMS(const std::vector<double> &values) {
    if (values.empty()) {
        throw std::invalid_argument("The input vector must not be empty.");
    }
    double sum_of_squares = 0; // needs to be fixed
    for (double value: values) {
        sum_of_squares += value * value; // Potential Overflow
    }
    double meanOfSquares = sum_of_squares / values.size(); // Potential Overflow
    return std::sqrt(meanOfSquares);
}

double calculateVariance(const std::vector<double> &values) {
    if (values.empty()) {
        throw std::invalid_argument("The input vector must not be empty.");
    }

    double mean = calculateMean(values);

    double sum_of_squared_differences = 0.0;
    for (double value: values) {
        sum_of_squared_differences += std::pow(value - mean, 2); // Potential Overflow
    }

    return sum_of_squared_differences / values.size();
}