#include "pch.h"
#include <algorithm>
#include "MathLibrary.h"
#include <cmath>
using std::sort;
using std::vector;
using std::pow;

MATHLIBRARY_API double MeanCALC(const vector<double>& numbers)
{
    if (numbers.empty()) return 0.0; 
    double sum = 0.0;
    for (double num : numbers)
    {
        sum += num;
    }
    return sum / numbers.size();
}
MATHLIBRARY_API double MedianCALC(vector<double> numbers)
{
    if (numbers.empty()) return 0.0;
    sort(numbers.begin(), numbers.end());
    size_t n = numbers.size();
    if (n % 2 == 0)
    {
        return (numbers[n /2 -1] +numbers[n /2]) /2.0;
    }
    else
    {
        return numbers[n /2];
    }
}
MATHLIBRARY_API double SQRTCALC(const vector<double>& numbers)
{
    if (numbers.empty()) return 0.0;
    double sumOfsqrt = 0.0;
    for (double num : numbers) {
        sumOfsqrt += pow(num, 2);
    }
    return std::sqrt(sumOfsqrt / numbers.size());
}
MATHLIBRARY_API double varCALC(const vector<double>& numbers)
{
    if (numbers.empty()) return 0.0;
    double mean = MeanCALC(numbers);
    double sumOfsqrt = 0.0;
    for (double num : numbers)
    {
        sumOfsqrt += std::pow(num - mean, 2);
    }
    return sumOfsqrt / numbers.size();
}
