#pragma once
#include <vector>


#ifdef HWDLL_EXPORTS
#define HWDLL_API __declspec(dllexport)
#else
#define HWDLL_API __declspec(dllimport)
#endif

using std::vector;




extern "C" __declspec(dllexport) double Average(const vector <double>& numbers);

extern "C" __declspec(dllexport) double Median(const vector<double>& numbers);

extern "C" __declspec(dllexport) double AverageSqr(const vector<double>& numbers);

extern "C" __declspec(dllexport)  double Dispersion(const vector<double>& numbers);