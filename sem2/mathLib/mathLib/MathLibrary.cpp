#include "pch.h"
#include <vector>
#include <iostream>
#include <utility>
#include <limits.h>
#include <algorithm>
#include "MathLibrary.h"



float average(const std::vector<float> numbers) {
	size_t length = numbers.size();

	if (length == 0)
		return 0;

	float sum = 0;
	for (const float& number : numbers) {
		sum += number;
	}
	return sum / length;
}

float median(std::vector<float> numbers) {
	size_t length = numbers.size();
	float sum = 0;

	if (length == 0)
		return 0; 

	sort(numbers.begin(), numbers.end());
	if (length % 2 == 0)
		return (numbers[length / 2 - 1] + numbers[length / 2]) / 2;
	else
		return numbers[length / 2];
}


float averagesqrt(const std::vector<float> numbers) {
	size_t length = numbers.size();

	if (length == 0)
		return 0;

	float sum = 0;
	for (const float& number : numbers) {
		sum += number*number;
	}
	return sqrt(sum / length);
}

double dispersion(const std::vector<float> numbers) {
	size_t length = numbers.size();

	if (length == 0)
		return 0;
	float avg = average(numbers);
	double sum = 0;
	for (const float& number : numbers) {
		sum += pow(number - avg,2);
	}
	return sum / length;
}
