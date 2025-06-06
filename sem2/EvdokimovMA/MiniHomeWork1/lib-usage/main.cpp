#include <iostream>
#include "include/libMath.h"

int main() {
	const double     arr[] = { 5, 3, 7, 2, 1, 6, 4 };
	constexpr size_t size  = std::size(arr);

	std::cout << "Average: " << MathLib::average(arr, size) << std::endl;
	std::cout << "Median: " << MathLib::median(arr, size) << std::endl;
	std::cout << "Root mean square: " << MathLib::rootMeanSquare(arr, size) << std::endl;
	std::cout << "Variance: " << MathLib::variance(arr, size) << std::endl;

	return 0;
}