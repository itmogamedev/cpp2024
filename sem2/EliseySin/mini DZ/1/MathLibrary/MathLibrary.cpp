#include "pch.h"
#include "MathLibrary.h"
#include <vector>
#include <algorithm>
#include <cmath>

double mean(const double* data, int size) {
    if (size <= 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < size; ++i) sum += data[i];
    return sum / size;
}

double median(const double* data, int size) {
    if (size <= 0) return 0.0;
    std::vector<double> temp(data, data + size);
    std::sort(temp.begin(), temp.end());
    if (size % 2 == 0) {
        return (temp[size / 2 - 1] + temp[size / 2]) / 2.0;
    }
    return temp[size / 2];
}

double rootMeanSquare(const double* data, int size) {
    if (size <= 0) return 0.0;
    double sumSquares = 0.0;
    for (int i = 0; i < size; ++i) sumSquares += data[i] * data[i];
    return std::sqrt(sumSquares / size);
}

double variance(const double* data, int size) {
    if (size <= 0) return 0.0;
    double m = mean(data, size);
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        double diff = data[i] - m;
        sum += diff * diff;
    }
    return sum / size;
}
