#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#ifdef Dll1_EXPORTS
#define Dll1_API __declspec(dllexport)
#else
#define Dll1_API __declspec(dllimport)
#endif // Dll1_EXPORTS

extern "C" {
	Dll1_API float arm(std::vector<float>& numbers);
	Dll1_API float med(std::vector<float>& numbers);
	Dll1_API float dsp(std::vector<float>& numbers);
	Dll1_API float sq(std::vector<float>& numbers);
}