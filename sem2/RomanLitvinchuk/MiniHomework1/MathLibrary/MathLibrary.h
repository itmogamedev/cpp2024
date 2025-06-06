#pragma once
#include <vector>
#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif


extern "C" MATHLIBRARY_API double AverageArith(std::vector<double> Numbers);
extern "C" MATHLIBRARY_API double Median(std::vector<double> Numbers);
extern "C" MATHLIBRARY_API double AverageQuad(std::vector<double> Numbers);
extern "C" MATHLIBRARY_API double Variance(std::vector<double> Numbers);