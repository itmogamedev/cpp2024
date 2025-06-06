#include "library.h"

#include <algorithm>
#include <iostream>
#include <cmath>

/*
 * Sorting the array using quicksort algorithm
 */

void partition(double* arr, const size_t size, const size_t pivot) {
	const double pivot_value= arr[pivot];
	size_t left = 0;
	size_t right = size - 1;

	while (left < right) {
		while (arr[left] < pivot_value) {
			left++;
		}

		while (arr[right] > pivot_value) {
			right--;
		}

		if (left < right) {
			std::swap(arr[left], arr[right]);
		}
	}
}

void sort(double* arr, const size_t size) {
	if (size <= 1) {
		return;
	}

	const size_t pivot = size / 2;
	partition(arr, size, pivot);

	sort(arr, pivot);
	sort(arr + pivot, size - pivot);
}



/*
 * Hometask
 */

double MathLib::average(const double* arr, const size_t size) {
	if (size == 0) {
		return 0;
	}

	double sum = 0;

	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}

	return sum / size;
}

double MathLib::median(const double* arr, const size_t size) {
	if (size == 0) {
		return 0;
	}

	const auto arr_copy = new double[size];
	std::copy_n(arr, size, arr_copy);
	sort(arr_copy, size);

	const double median = size % 2 == 0
		? (arr_copy[size / 2 - 1] + arr_copy[size / 2]) / 2
		: arr_copy[size / 2];

	delete[] arr_copy;
	return median;
}

double MathLib::rootMeanSquare(const double* arr, const size_t size) {
	if (size == 0) {
		return 0;
	}

	double sum = 0;

	for (int i = 0; i < size; i++) {
		sum += arr[i] * arr[i];
	}

	return sqrt(sum / size);
}

double MathLib::variance(const double* arr, const size_t size) {
	if (size == 0) {
		return 0;
	}

	const double avg = average(arr, size);
	double sum = 0;

	for (int i = 0; i < size; i++) {
		sum += (arr[i] - avg) * (arr[i] - avg);
	}

	return sum / size;
}