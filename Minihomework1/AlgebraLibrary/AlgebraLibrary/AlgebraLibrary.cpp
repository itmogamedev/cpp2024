#include "pch.h" 
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime> 
#include "MergeSort.h"
#include "AlgebraLibrary.h"
            
//Ğåàëèçàöèÿ âñåõ ìåòîäîâ áèáëèîòåêè

std::vector<double> RandomInit(int number)
{
    std::srand(std::time(NULL));
    std::vector<double> numbers;
    for (int i = 0; i < number; ++i)
    {
        numbers.push_back((double)std::rand() / RAND_MAX + std::rand());
    }

    return numbers;
}

void WriteVector(std::vector<double> numbers, char sep)
{
    for(int i = 0; i < numbers.size() - 1; ++i)
    {
        std::cout << numbers[i] << sep;
    }

    std::cout << numbers[numbers.size() - 1] << std::endl;
}

double ArithmetiñMean(std::vector<double> numbers)
{
    double Sum = 0;
    for(int i = 0; i < numbers.size(); ++i)
    {
        Sum += numbers[i];
    }

    return Sum / numbers.size();
}

double Median(std::vector<double> numbers)
{
    MergeSort(numbers, 0, numbers.size() - 1);

    if(numbers.size() % 2 == 1)
    {
        return numbers[(numbers.size() - 1) / 2];
    }
    else
    {
        return (numbers[numbers.size() / 2] + numbers[(numbers.size() / 2) - 1]) / 2;
    }
}

double SquareMean(std::vector<double> numbers)
{
    double SquareSum = 0;
    for (int i = 0; i < numbers.size(); ++i)
    {
        SquareSum += numbers[i]*numbers[i];
    }

    return sqrt(SquareSum / numbers.size());
}

double Dispersion(std::vector<double> numbers)
{
    double ArithmMean = ArithmetiñMean(numbers);
    double SquareDivSum = 0;

    for (int i = 0; i < numbers.size(); ++i)
    {
        SquareDivSum += (numbers[i] - ArithmMean) * (numbers[i] - ArithmMean);
    }

    return SquareDivSum / numbers.size();
}

void GeneralStats(std::vector<double> numbers)
{
    std::cout << "For numbers: "; 
    WriteVector(numbers);
         
    std::cout << "ArithmeticMean: " << ArithmetiñMean(numbers) << std::endl;
    std::cout << "Median: " << Median(numbers) << std::endl;
    std::cout << "SquareMean: " << SquareMean(numbers) << std::endl;
    std::cout << "Dispersion: " << Dispersion(numbers) << std::endl;
}


