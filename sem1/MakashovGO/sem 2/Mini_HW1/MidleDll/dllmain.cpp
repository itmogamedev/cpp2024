#include "pch.h"
#include "MidleLib.h"

double Math::AveArith(std::vector <double> nums)
{
	double total = 0;
	for (double i : nums)
	{
		total += i;
	}
	return total / nums.size();
}

double Math::Median(std::vector <double> nums)
{
	std::sort(nums.begin(), nums.end());
	if (nums.size() % 2 == 1)
	{
		return nums.at(nums.size() / 2);
	}
	else
	{
		return (nums.at(nums.size() / 2) + nums.at(nums.size() / 2 + 1)) / 2;
	}
}

double Math::AveQuad(std::vector <double> nums)
	{
		const double x = AveArith(nums);
		double sum = 0;
		for (double i : nums)
		{
			sum += pow(i - x, 2);
		}
		return pow(sum / nums.size(), 0.5);
	}

double Math::Variance(std::vector <double> nums)
	{
		const double x = AveArith(nums);
		for (int i = 0; i < nums.size(); i++)
		{
			nums[i] = x - nums[i];
		}
		const double new_x = AveArith(nums);
		for (int i = 0; i < nums.size(); i++)
		{
			nums[i] = pow(x - nums[i], 2);
		}
		return AveArith(nums);
	}