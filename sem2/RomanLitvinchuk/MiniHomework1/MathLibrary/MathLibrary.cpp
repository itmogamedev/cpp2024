#include "pch.h"
#include <vector>
#include <cmath>
#include "MathLibrary.h"

double AverageArith(std::vector<double> Numbers) 
{
	double Sum = 0;
	int Count = Numbers.size();
	for (int i = 0; i != Numbers.size(); ++i) 
	{
		Sum += Numbers[i];
	}
	return Sum / Count;
}

double Median(std::vector<double> Numbers) 
{
	if (Numbers.size() % 2 != 0)
	{
		return Numbers[Numbers.size() / 2];
	}
	else 
	{
		return (Numbers[Numbers.size() / 2] + Numbers[Numbers.size() / 2 - 1]) / 2.0;
	}
}

double AverageQuad(std::vector<double> Numbers) 
{
	double QuadSum = 0;
	int count = Numbers.size();
	for (int i = 0; i != Numbers.size(); ++i) 
	{
		QuadSum += Numbers[i] * Numbers[i];
	}
	return sqrt(QuadSum/count);
}

double Variance(std::vector<double> Numbers) 
{
	double Average = AverageArith(Numbers);
	int count = Numbers.size();
	double Sum = 0;
	for (int i = 0; i != Numbers.size(); ++i) 
	{
		Sum += (Numbers[i] - Average) * (Numbers[i] - Average);
	}
	return Sum/count;
}