#include <iostream>

int main()
{
	int input = 0;
	int reverse = 0;
	std::cout << "Enter a number here, please: ";
	std::cin >> input;
	while (input > 0) {
		reverse = reverse * 10;
		reverse += input % 10;
		input = input / 10;
	}
	std::cout << "Reversed number: " << reverse;
}