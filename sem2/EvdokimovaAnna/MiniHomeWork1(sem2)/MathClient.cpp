#include <iostream>
#include <vector>
#include "MathLibrary.h"

using std::vector;
using std::cout;
using std::endl;

int main() {
    // вектор с числами
    vector<double> numbers = { 1.0, 2.1, 3.0, 4.3, 5.0 };

    // Функция для подсчета среднего арифметического
    double mean = CalculateMean(numbers);
    cout << "Mean: " << mean << endl;

    // Функция для подсчета медианы
    double median = CalculateMedian(numbers);
    cout << "Median: " << median << endl;

    // Функция для подсчета среднего квадратического
    double quadraticMean = CalculateQuadraticMean(numbers);
    cout << "Quadratic Mean: " << quadraticMean << endl;

    // Функция для подсчета дисперсии
    double variance = CalculateVariance(numbers);
    cout << "Variance: " << variance << endl;

    return 0;
}
