#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H

#include <vector>

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

// Функция для подсчета среднего арифметического
extern "C" MATHLIBRARY_API double CalculateMean(const std::vector<double>& numbers);

// Функция для подсчета медианы    
extern "C" MATHLIBRARY_API double CalculateMedian(std::vector<double> numbers);

// Функция для подсчета среднего квадратического
extern "C" MATHLIBRARY_API double CalculateQuadraticMean(const std::vector<double>& numbers);

// Функция для подсчета дисперсии
extern "C" MATHLIBRARY_API double CalculateVariance(const std::vector<double>& numbers);


#endif // MATHLIBRARY_H