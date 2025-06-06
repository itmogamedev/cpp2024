#pragma once
#include <vector>

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

extern "C" MATHLIBRARY_API int average(std::vector<int> sequnce);

extern "C" MATHLIBRARY_API int median(std::vector<int> sequnce);

extern "C" MATHLIBRARY_API int average_square(std::vector<int> sequence);

extern "C" MATHLIBRARY_API int variance(std::vector<int> sequence);