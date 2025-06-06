#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

#include <vector>

extern "C" MATHLIBRARY_API double average(std::vector<double> a);

extern "C" MATHLIBRARY_API double median(std::vector<double> a);

extern "C" MATHLIBRARY_API double square_average(std::vector<double> a);

extern "C" MATHLIBRARY_API double variance(std::vector<double> a);