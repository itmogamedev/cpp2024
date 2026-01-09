#include "StatisticLib.h"
#include <algorithm>
#include <cmath>
#include <vector>

double CalculateAverage(double arr[], int count)
{
    if (count <= 0)
        return 0.0;

    double sum = 0.0;
    for (int i = 0; i < count; ++i)
    {
        sum += arr[i];
    }
    return sum / count;
}

double CalculateMedian(double arr[], int count)
{
    if (count <= 0)
        return 0.0;

    // Создаем копию массива в вектор для сортировки
    std::vector<double> temp(arr, arr + count);
    std::sort(temp.begin(), temp.end());

    if (count % 2 == 0)
    {
        // Если количество элементов четное, медиана - среднее двух центральных
        int mid = count / 2;
        return (temp[mid - 1] + temp[mid]) / 2.0;
    }
    else
    {
        // Если нечетное, медиана - центральный элемент
        return temp[count / 2];
    }
}

double CalculateRMS(double arr[], int count)
{
    if (count <= 0)
        return 0.0;

    double sumSquares = 0.0;
    for (int i = 0; i < count; ++i)
    {
        sumSquares += arr[i] * arr[i];
    }
    double meanSquares = sumSquares / count;
    return std::sqrt(meanSquares);
}

double CalculateVariance(double arr[], int count)
{
    if (count <= 0)
        return 0.0;

    double avg = CalculateAverage(arr, count);
    double sumDiffSq = 0.0;
    for (int i = 0; i < count; ++i)
    {
        double diff = arr[i] - avg;
        sumDiffSq += diff * diff;
    }
    return sumDiffSq / count;
}