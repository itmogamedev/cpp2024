#include "mathlib.h"

namespace MathLibrary
{
    double Arithmetic::mid(std::vector<int> numbers)
    {
        double total = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            total += numbers[i];
        }
        return total / numbers.size();
    }

    double Arithmetic::med(std::vector<int> numbers)
    {
        if (numbers.size() % 2 == 0)
        {
            return double(numbers[numbers.size()/2] + numbers[(numbers.size()/2)-1])/2;
        }
        else
        {
            return numbers[numbers.size() / 2];
        }
    }

    double Arithmetic::midsqrt(std::vector<int> numbers)
    {
        double total = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            total += numbers[i]* numbers[i];
        }
        return sqrt(total / numbers.size());
    }

    double Arithmetic::disp(std::vector<int> numbers)
    {
        double total = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            total += numbers[i];
        }
        double mid = total / numbers.size();
        total = 0;

        for (int i = 0; i < numbers.size(); i++)
        {
            total += (numbers[i]-mid) * (numbers[i]-mid);
        }

        return total / numbers.size();
    }
}