#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#ifdef HWDll_EXPORTS
#define HWDll_API __declspec(dllexport)
#else
#define HWDll_API __declspec(dllimport)
#endif // HWDll_EXPORTS

extern "C" {
	HWDll_API float averageArithmeticValue(std::vector<float>& numbers);
	HWDll_API float median(std::vector<float>& numbers);
	HWDll_API float averageSquareValue(std::vector<float>& numbers);
	HWDll_API float variance(std::vector<float>& numbers);
}
