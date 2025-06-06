#include <iostream>
#include "mathlib.h"
#include <sstream>
#include <string>

int main()
{
    std::vector<int> numbers;
    std::string string;

    std::cout << "Write numbers with space:" << "\n";
    std::getline(std::cin, string);

    std::istringstream iss(string);
    std::string number;
    while (iss >> number)
    {
        numbers.push_back(std::stoi(number));
    }
    std::cout << "ArithMid: " << MathLibrary::Arithmetic::mid(numbers) << "\n"
        << "Median: " << MathLibrary::Arithmetic::med(numbers) << "\n"
        << "SQRTMid: " << MathLibrary::Arithmetic::midsqrt(numbers) << "\n"
        << "Disp: " << MathLibrary::Arithmetic::disp(numbers);
}
