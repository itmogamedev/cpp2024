#pragma once

#ifdef dllmain_EXPORTS
#define dllmain_API __declspec(dllexport)
#else
#define dllmain_API __declspec(dllimport)
#endif

#include "iostream"
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

dllmain_API double arithmeticMean(const std::vector<double>& data);
dllmain_API double median(std::vector<double> data);
dllmain_API double meanSquare(const std::vector<double>& data);
dllmain_API double variance(const std::vector<double>& data);
