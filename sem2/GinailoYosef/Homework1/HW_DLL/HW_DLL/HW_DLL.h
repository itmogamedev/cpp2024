#pragma once

#ifdef HW_EXPORTS
#define HW_API __declspec(dllexport)
#else
#define HW_API __declspec(dllimport)
#endif

extern "C" HW_API float arithmetic_mean(float* args, int size);
extern "C" HW_API float median(float* args, int size);
extern "C" HW_API float mean_square(float* args, int size);
extern "C" HW_API float number_series_variance(float* args, int size);