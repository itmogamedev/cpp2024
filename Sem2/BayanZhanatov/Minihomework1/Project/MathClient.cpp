#include <iostream>
#include <vector>
#include "MathLibrary.h"

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<double> numbers = { 1.0, 2.1, 3.0, 4.3, 5.0 };
    double mean = CalculateMean(numbers);
    cout << "Mean: " << mean << endl;
    double median = CalculateMedian(numbers);
    cout << "Median: " << median << endl;
    double quadraticMean = CalculateQuadraticMean(numbers);
    cout << "Quadratic Mean: " << quadraticMean << endl;
    double variance = CalculateVariance(numbers);
    cout << "Variance: " << variance << endl;

    return 0;
}
