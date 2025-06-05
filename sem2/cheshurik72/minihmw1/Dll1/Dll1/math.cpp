#include "pch.h"
#include "math.h"

float arm(std::vector<float>& numbers) {
    float summ = 0;
    if (numbers.empty() != true) {
        for (int number : numbers) {
            summ += number;
        }
    }
    return summ / numbers.size();
}

float med(std::vector<float>& numbers) {
    if (numbers.size() == 0) {
        throw std::runtime_error("Vector is empty");
    }

    std::sort(numbers.begin(), numbers.end());

    if (numbers.size() % 2 == 0) {
        return (numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) / 2;
    }
    else {
        return numbers[numbers.size() / 2];
    }
}

float dsp(std::vector<float>& numbers) {
    if (numbers.size() == 0) {
        throw std::runtime_error("Vector is empty");
    }

    float summ = 0;
    for (int number : numbers) {
        summ += number * number;
    }

    return std::sqrt(summ / numbers.size());
}

float sq(std::vector<float>& numbers) {
    if (numbers.size() == 0) {
        throw std::runtime_error("Vector is empty");
    }

    float mean = 0;
    for (int number : numbers) {
        mean += number;
    }
    mean /= numbers.size();

    double resultingVariance = 0;
    for (int number : numbers) {
        resultingVariance += (number - mean) * (number - mean);
    }

    return resultingVariance / numbers.size();
}