#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H

#include <vector>

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

extern "C" MATHLIBRARY_API double MeanCALC(const std::vector<double>& numbers);
extern "C" MATHLIBRARY_API double MedianCALC(std::vector<double> numbers);
extern "C" MATHLIBRARY_API double SQRTCALC(const std::vector<double>& numbers);
extern "C" MATHLIBRARY_API double varCALC(const std::vector<double>& numbers);

#endif // MATHLIBRARY_H