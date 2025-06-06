#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H

#ifdef MATHLIBRARY_EXPORTS
#define MATH_API __declspec(dllexport)
#else
#define MATH_API __declspec(dllimport)
#endif

#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

extern "C" {
    MATH_API double mean(const std::vector<double>& data);
    MATH_API double median(std::vector<double> data);
    MATH_API double rootMeanSquare(const std::vector<double>& data);
    MATH_API double variance(const std::vector<double>& data);
}

#endif
