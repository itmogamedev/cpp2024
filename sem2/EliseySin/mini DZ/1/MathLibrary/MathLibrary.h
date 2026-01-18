#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

extern "C" {
    MATHLIBRARY_API double mean(const double* data, int size);
    MATHLIBRARY_API double median(const double* data, int size);
    MATHLIBRARY_API double rootMeanSquare(const double* data, int size);
    MATHLIBRARY_API double variance(const double* data, int size);
}
