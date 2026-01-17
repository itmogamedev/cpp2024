#include "pch.h"
#include "framework.h"
#include "math_funcs.h"
#include <algorithm> 


float sum(std::vector<float> vec) {

	float sum_of_elems = 0;

	for (float el : vec)
		sum_of_elems += el;

	return sum_of_elems;
}


void sort(std::vector<float>* vec) {
	std::sort(vec->begin(), vec->end(), [](float a, float b) { return a < b; });
}

float ArithmeticMean(std::vector<float> vec) {
	return sum(vec) / vec.size();
}

float Median(std::vector<float> vec) {
	sort(&vec);

	if (vec.size() % 2 == 0) {
		return ArithmeticMean({ vec[vec.size() / 2 - 1], vec[vec.size() / 2] });
	}
	else {
		return vec[(int)(vec.size() / 2)];
	}
}

float RootMeanSquare(std::vector<float> vec) {

	std::for_each(vec.begin(), vec.end(), [](float& el) { el = pow(el, 2); });

	return sqrt(ArithmeticMean(vec));
}

float Variance(std::vector<float> vec) {
	float mean = ArithmeticMean(vec);

	std::for_each(vec.begin(), vec.end(), [=](float& el) { el = pow(el - mean, 2); });

	return ArithmeticMean(vec);
}