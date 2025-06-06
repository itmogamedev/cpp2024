#include "MidleLib.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>



std::vector<double> split(const std::string& line)
{
    std::vector<double> splist;
    std::stringstream ss(line);
    double num;

    while (ss >> num)
    {
        splist.push_back(num);
    }

    return splist;
}

int main()
{
    int n;
	Math math{};
	std::vector <double> nums;
	std::string seq;
	std::cout << "enter a sequence of numbers: ";
	std::getline(std::cin, seq);
    nums = split(seq);
    std::cout << "1. arithmetic mean\n";
    std::cout << "2. median\n";
    std::cout << "3. quadratic mean\n";
    std::cout << "4. variance of the numerical series\n";
    std::cout << "enter number of func: ";
    std::cin >> n; 
    switch (n)
    {
    case 1:
        std::cout << math.AveArith(nums);
    case 2:
        std::cout << math.Median(nums);
    case 3:
        std::cout << math.AveQuad(nums);
    case 4:
        std::cout << math.Variance(nums);
    default:
        break;
    }
    
    
}