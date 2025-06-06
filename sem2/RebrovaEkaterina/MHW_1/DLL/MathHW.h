#pragma once

#ifdef MATHHW_EXPORTS
#define MATHHW_API __declspec(dllexport)
#else
#define MATHHW_API __declspec(dllimport)
#endif
#include <vector>

extern "C" MATHHW_API double calculateMean(std::vector <double> data);

extern "C" MATHHW_API double calculateMedian(std::vector <double> data);

extern "C" MATHHW_API double calculateRootMeanSquare(std::vector <double> data);

extern "C" MATHHW_API double calculateVariance(std::vector <double> data);