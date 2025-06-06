
#pragma once

#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif
#include <vector>

extern "C" MYDLL_API float average_Arithmetic(std::vector<float>);
extern "C" MYDLL_API float median(std::vector<float>);
extern "C" MYDLL_API float average_square(std::vector<float>);
extern "C" MYDLL_API float dispersion(std::vector<float>);