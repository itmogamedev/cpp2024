#include "pch.h"
#include "MathLibrary.h"
#include <vector>

double average(std::vector<double> a)
{
    double b = 0;
    for (int i = 0; i < a.size(); i++)
    {
        b += a[i];
    }
    return b / a.size();
}

double median(std::vector<double> a)
{
    if (a.size() % 2 == 0)
    {
        return (a[a.size() / 2] + a[a.size() / 2 - 1]) / 2;
    }
    else
    {
        return a[a.size() / 2];
    }
}

double square_average(std::vector<double> a)
{
    double b = 0;
    for (int i = 0; i < a.size(); i++)
    {
        b += pow(a[i], 2);
    }
    return pow(b / a.size(), 0.5);
}

double variance(std::vector<double> a)
{
    double b = average(a);
    double c = 0;
    for (int i = 0; i < a.size(); i++)
    {
        c += pow((a[i] - b), 2);
    }
    return c / a.size();
}
