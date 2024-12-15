#include <iostream>

void printReverseNumberStep(unsigned int number2Reverse) {
	if (number2Reverse < 10)
	{
		std::cout << number2Reverse;
	}
	else {
		std::cout << number2Reverse % 10;
		printReverseNumberStep(number2Reverse/10);
	}
}

void reverseNumber() {
	unsigned int number;
	std::cin >> number;
	printReverseNumberStep(number);
}