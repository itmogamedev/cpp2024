#include "statistics_lib.h"

namespace Statistics {

    double calculateMean(const std::vector<double>& data) {
        if (data.empty()) return 0.0;
        double sum = 0.0;
        for (double value : data) {
            sum += value;
        }
        return sum / data.size();
    }

    double calculateMedian(std::vector<double> data) {
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

    double calculateRootMeanSquare(const std::vector<double>& data) {
        if (data.empty()) return 0.0;
        double sum = 0.0;
        for (double value : data) {
            sum += value * value;
        }
        return std::sqrt(sum / data.size());
    }

    double calculateVariance(const std::vector<double>& data) {
        if (data.empty()) return 0.0;
        double mean = calculateMean(data);
        double sum = 0.0;
        for (double value : data) {
            sum += (value - mean) * (value - mean);
        }
        return sum / data.size();
    }

}