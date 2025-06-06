#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "MYDLL.h"
#include <vector>
#include <algorithm>
#include <cmath>


float average_Arithmetic(std::vector<float> nums) {
	int vecsize = nums.size();
	float sum = 0.0;
	for (int i = 0; i < vecsize; i++) {
		sum += nums[i];
	}
	return sum / vecsize;

}

float median(std::vector<float> nums) {
	std::sort(nums.begin(), nums.end());
	if (nums.size() % 2 == 0) {
		return nums[(nums.size() + 1) / 2];
	}
	else {
		return ((nums[nums.size() / 2] + nums[nums.size() / 2 + 1]) / 2);
	}

}

float average_square(std::vector<float> nums){
	int vecsize = nums.size();
	float sum = 0.0;
	for (int i = 0; i < vecsize; i++) {
		sum += nums[i]*nums[i];
	}
	return pow(sum / vecsize,0.5);
}

float dispersion(std::vector<float> nums) {
	float avg = average_Arithmetic(nums);
	int vecsize = nums.size();
	float sum = 0.0;
	for (int i = 0; i < vecsize; i++) {
		sum += pow(nums[i] - avg, 2);
	}
	return sum / vecsize;
}
