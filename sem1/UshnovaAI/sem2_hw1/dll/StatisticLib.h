#pragma once

#ifdef STATISTICLIB_EXPORTS
#define STATISTICLIB_API __declspec(dllexport)
#else
#define STATISTICLIB_API __declspec(dllimport)
#endif

extern "C" {

    // Вычисление среднего арифметического
    STATISTICLIB_API double CalculateAverage(double arr[], int count);

    // Вычисление медианы
    STATISTICLIB_API double CalculateMedian(double arr[], int count);

    // Вычисление среднего квадратического (RMS)
    STATISTICLIB_API double CalculateRMS(double arr[], int count);

    // Вычисление дисперсии
    STATISTICLIB_API double CalculateVariance(double arr[], int count);
}