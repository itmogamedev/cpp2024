#include <iostream>
#include <vector>
#include "MathLibrary.h"
#include <string>
#include <sstream>

int main() 
{
	std::cout << "Enter a numbers separated by SPACE " << std::endl;
	std::vector<double> Numbers;
	std::string input;
	std::getline(std::cin, input);
	std::istringstream iss(input);
	double number{};
	while (iss >> number) 
	{
		Numbers.push_back(number);
	}
	if (Numbers.size() == 0) 
	{
		std::cout << "0 numbers!" << std::endl;
		return 1;
	}
	std::cout << "Average Arithmetic: " << AverageArith(Numbers) << std::endl;
	std::cout << "Median: " << Median(Numbers) << std::endl;
	std::cout << "Average quadratic: " << AverageQuad(Numbers) << std::endl;
	std::cout << "Variance: " << Variance(Numbers) << std::endl;
	return 0;
}
