#include "pch.h"
#include <vector>
#include <numeric>
#include <cmath>
#include "HWDLL.h"




using std::vector;

double Average(const vector <double>& numbers) {
    if (numbers.empty()) {
        return 0.0;
    }
    double sumvector = std::accumulate(numbers.begin(), numbers.end(), 0.0);
    return sumvector / numbers.size();
}

double Median(const vector <double>& numbers) {
    if (numbers.empty()) {
        return 0.0;
    }
    if (numbers.size() % 2 == 0) {
        return (numbers[numbers.size() / 2] + numbers[numbers.size() / 2 + 1]) / 2;
    }
    if (numbers.size() % 2 != 0) {
        return numbers[numbers.size() / 2 + 1];
    }

}

double AverageSqr(const vector <double>& numbers) {
    if (numbers.empty()) {
        return 0.0;
    }
    double sumsqrs = 0.0;
    for (const double number : numbers) {
        sumsqrs += number * number;
    }
    return sqrt(sumsqrs / numbers.size());

}

double Dispersion(const vector<double>& numbers) {
    if (numbers.empty()) {
        return 0.0;
    }

    double mean = 0.0;
    double variance = 0.0;


    mean = std::accumulate(numbers.begin(), numbers.end(), 0.0);
    mean /= numbers.size();


    for (const double number : numbers) {
        variance += (number - mean) * (number - mean);
    }
    variance /= numbers.size();

    return variance;
}