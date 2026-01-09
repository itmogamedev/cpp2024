#pragma once
#include <vector>
#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

extern "C" MATHLIBRARY_API float average(
    const std::vector<float>);
extern "C" MATHLIBRARY_API float median(
    std::vector<float>);
extern "C" MATHLIBRARY_API float averagesqrt(
    const std::vector<float>);
extern "C" MATHLIBRARY_API double dispersion(
    const std::vector<float>);