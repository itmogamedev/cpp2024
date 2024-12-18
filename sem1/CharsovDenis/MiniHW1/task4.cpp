#include <iostream>

int main()
{
	std::cout << "Input the number: ";
	int number{};
	std::cin >> number;

	int reverseNum{};

	while (number != 0) {
		int lastNum = number % 10;
		reverseNum = reverseNum * 10 + lastNum;
		number /= 10;
	}

	std::cout << "The reverse number: " << reverseNum;
}
