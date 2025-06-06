#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>

double calculateMean(const std::vector<double> &values);

double calculateMedian(std::vector<double> values);

double calculateRMS(const std::vector<double> &values);

double calculateVariance(const std::vector<double> &values);

template<std::convertible_to<double> T>
std::vector<double> getDoubleVector(const std::vector<T> &values) {
    std::vector<double> doubleValues;
    doubleValues.reserve(values.size());
    std::transform(values.begin(), values.end(), std::back_inserter(doubleValues),
                   [](const T &value) { return static_cast<double>(value); });
    return doubleValues;
}

template<std::convertible_to<double> T>
double calculateMean(const std::vector<T> &values) {
    std::vector<double> copy = getDoubleVector(values);
    return calculateMean(copy);
}

template<std::convertible_to<double> T>
double calculateMedian(const std::vector<T> &values) {
    return calculateMedian(getDoubleVector(values));
}

template<std::convertible_to<double> T>
double calculateRMS(const std::vector<T> &values) {
    return calculateRMS(getDoubleVector(values));
}

template<std::convertible_to<double> T>
double calculateVariance(const std::vector<T> &values) {
    return calculateVariance(getDoubleVector(values));
}
