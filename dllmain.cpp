#include "pch.h"
#include "MathLibrary.h"
#include <algorithm> // для sort
#include <cmath> // для pow и sqrt

using std::sort;
using std::vector;
using std::pow;

// Функция для подсчета среднего арифметического
MATHLIBRARY_API double CalculateMean(const vector<double>& numbers) 
{
    if (numbers.empty()) return 0.0; // проверка на пустой вектор
    double sum = 0.0;
    for (double num : numbers) 
    {
        sum += num; 
    }
    return sum / numbers.size(); 
}

// Функция для подсчета медианы
MATHLIBRARY_API double CalculateMedian(vector<double> numbers) 
{
    if (numbers.empty()) return 0.0; 
    sort(numbers.begin(), numbers.end()); // Сортируем вектор
    size_t n = numbers.size();
    if (n % 2 == 0) 
    {
        // если кол-во четное, возвращаем среднее двух средних
        return (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
    }
    else 
    {
        // если кол-во нечетное, возвращаем средний элемент
        return numbers[n / 2];
    }
}

// Функция для подсчета среднего квадратического
MATHLIBRARY_API double CalculateQuadraticMean(const vector<double>& numbers) 
{
    if (numbers.empty()) return 0.0; 
    double sumOfSquares = 0.0;
    for (double num : numbers) {
        sumOfSquares += pow(num, 2); 
    }
    return std::sqrt(sumOfSquares / numbers.size()); 
}

// Функция для подсчета дисперсии
MATHLIBRARY_API double CalculateVariance(const vector<double>& numbers) 
{
    if (numbers.empty()) return 0.0; 
    double mean = CalculateMean(numbers); 
    double sumOfSquares = 0.0;
    for (double num : numbers) 
    {
        sumOfSquares += std::pow(num - mean, 2); 
    }
    return sumOfSquares / numbers.size(); 
}
