#ifndef STATISTICS_LIB_H
#define STATISTICS_LIB_H

#include <vector>

class StatisticsLib {
public:
    static double calculateMean(const std::vector<double>& data);
    static double calculateMedian(std::vector<double> data); // Передаем копию для сортировки
    static double calculateVariance(const std::vector<double>& data);
    static double calculateStdDev(const std::vector<double>& data);
};

#endif // STATISTICS_LIB_H