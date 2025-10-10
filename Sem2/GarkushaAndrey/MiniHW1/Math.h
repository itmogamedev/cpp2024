#pragma once
#include <vector>

namespace stats {

	class Math
	{
	public:
		double mean(const std::vector<int>& numbers);
		double median(const std::vector<int>& numbers);
		double RMS(const std::vector<int>& numbers);
		double disp(const std::vector<int>& numbers);
	};
}