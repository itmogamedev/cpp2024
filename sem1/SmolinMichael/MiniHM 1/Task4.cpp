#include <iostream>
#include <iomanip>

int main() {
	int number;
	int reversedNumber = 0;
	int digitsNumber = 0;

	std::cout << "Enter a number to reverse: ";
	std::cin >> number;

	while (number != 0)
	{
		++digitsNumber;
		reversedNumber *= 10;
		reversedNumber += number % 10;
		number /= 10;
	}

	std::cout << std::setw(digitsNumber) << std::setfill('0') << reversedNumber;

}