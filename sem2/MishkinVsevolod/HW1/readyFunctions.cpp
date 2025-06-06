#include "readyFunctions.hpp"
#include <algorithm>
#include <cmath>

double arithmeticMean(std::vector<double>& numbers) {
    double sum = 0.0;
    for (double num : numbers) sum += num;
    return sum / numbers.size();
}

double median(std::vector<double> numbers) {
    std::sort(numbers.begin(), numbers.end());
    return numbers[numbers.size() / 2];
}

double averageSquareValue(std::vector<double>& numbers) {
    std::vector<double> squares(numbers.size());
    for (int i = 0; i < numbers.size(); i++) {
        squares[i] = numbers[i] * numbers[i];
    }
    return sqrt(arithmeticMean(squares));
}

double dispersion(std::vector<double>& numbers) {
    double tempMean = arithmeticMean(numbers);
    double sum = 0.0;
    for (double num : numbers) {
        sum += (num - tempMean) * (num - tempMean);
    } 
    return sum / numbers.size();
}