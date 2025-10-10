#include "Math.h"
#include <algorithm>
#include <math.h>

double stats::Math::mean(const std::vector<int>& numbers) {
	double total{ 0 };
	if (numbers.empty()) return 0.0;

	for (auto it = numbers.begin(); it != numbers.end(); ++it) {
		total += *it;
	}
	return total / static_cast<double>(numbers.size());
}

double stats::Math::median(const std::vector<int>& numbers) {
	if (numbers.empty()) return 0.0;
	std::vector<int> sortedVec = numbers;
	size_t size = sortedVec.size();

	std::sort(sortedVec.begin(), sortedVec.end());

	if (size % 2 != 0) {
		return static_cast<double>(sortedVec[size / 2]);
	}
	else {
		return static_cast<double>((sortedVec[size / 2] + sortedVec[size / 2 - 1]) / 2.0);
	}
}

double stats::Math::RMS(const std::vector<int>& numbers) {
	if (numbers.empty()) return 0.0;
	double sumSquares = 0.0;

	for (int num : numbers) {
		sumSquares += num * num;
	}

	double meanSquares = sumSquares / static_cast<double>(numbers.size());
	return sqrt(meanSquares);
}

double stats::Math::disp(const std::vector<int>& numbers) {
	if (numbers.empty()) return 0.0;

	double mu = mean(numbers);
	double sumSqDiff = 0.0;

	for (int num : numbers) {
		double diff = static_cast<double>(num) - mu;
		sumSqDiff += diff * diff;
	}

	return sumSqDiff / static_cast<double>(numbers.size());
}