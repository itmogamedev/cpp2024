#pragma once
#include <vector>

#ifdef ALGEBRALIBRARY_EXPORTS
#define ALGEBRALIBRARY_API __declspec(dllexport)
#else
#define ALGEBRALIBRARY_API __declspec(dllimport)
#endif

//Инициализация рандомного массива из n чисел с плавающей точкой
extern "C++" ALGEBRALIBRARY_API std::vector<double> RandomInit(int number);

//Вывод массива в консоль
extern "C" ALGEBRALIBRARY_API void WriteVector(std::vector<double> numbers, char sep = ',');

//Среднее арифметическое
extern "C" ALGEBRALIBRARY_API double ArithmetiсMean(std::vector<double> numbers);

//Медиана массива
extern "C" ALGEBRALIBRARY_API double Median(std::vector<double> numbers);

//Среднее квадратичное
extern "C" ALGEBRALIBRARY_API double SquareMean(std::vector<double> numbers);

//Дисперсия набора чисел
extern "C" ALGEBRALIBRARY_API double Dispersion(std::vector<double> numbers);

//Вывод всех данных о наборе чисел
extern "C" ALGEBRALIBRARY_API void GeneralStats(std::vector<double> numbers);