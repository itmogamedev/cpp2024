#include <iostream>
#include <vector>
#include "StatisticsLib.h"

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<double> data = { 10, 20, 30, 40, 50 };

    double mean = StatisticsLib::calculateMean(data);
    double median = StatisticsLib::calculateMedian(data);
    double variance = StatisticsLib::calculateVariance(data);
    double stdDev = StatisticsLib::calculateStdDev(data);

    std::cout << "Среднее арифметическое: " << mean << std::endl;
    std::cout << "Медиана: " << median << std::endl;
    std::cout << "Дисперсия: " << variance << std::endl;
    std::cout << "Среднее квадратическое: " << stdDev << std::endl;

    return 0;
}