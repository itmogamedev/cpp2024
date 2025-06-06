#ifndef MATH_LIBRARY_H
#define MATH_LIBRARY_H

#pragma once

#include <cstddef>

namespace MathLib {
	double average(const double* arr, size_t size);
	double median(const double* arr, size_t size);
	double rootMeanSquare(const double* arr, size_t size);
	double variance(const double* arr, size_t size);
}

#endif //MATH_LIBRARY_H
