#pragma once
#include<vector>

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

extern "C" MATHLIBRARY_API double calculateMean(const std::vector<int>& numbers);

extern "C" MATHLIBRARY_API double calculateMedian(std::vector<int> numbers);

extern "C" MATHLIBRARY_API double calculateMeanSquare(const std::vector<int>& numbers);

extern "C" MATHLIBRARY_API double calculateVariance(const std::vector<int>& numbers);