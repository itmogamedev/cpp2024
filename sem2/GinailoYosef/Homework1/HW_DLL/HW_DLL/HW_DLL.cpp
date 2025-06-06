#include "pch.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include "HW_DLL.h"

float arithmetic_mean(float* args, int size) {
    std::vector<float> vec(args, args + size);
    float sum = 0;
    for (float num : vec) sum += num;
    return sum / size;
}

bool compare(float a, float b) { return a < b; }
float median(float* args, int size) {
    std::vector<float> vec(args, args + size);
    if (vec.empty()) { return 0; };

    std::sort(vec.begin(), vec.end(), compare);
    size = vec.size();
        
    if (size % 2 == 0)
        return (vec[size / 2 - 1] + vec[size / 2]) / 2;
    else
        return vec[size / 2];
}

float mean_square(float* args, int size) {
    std::vector<float> vec(args, args + size);
    float sum = 0;
    for (float num : vec) sum += std::pow(num, 2);
    return std::pow(sum/size, .5);
}

float number_series_variance(float* args, int size) {
    return std::pow(mean_square(args, size), 2) - std::pow(arithmetic_mean(args, size), 2);
}