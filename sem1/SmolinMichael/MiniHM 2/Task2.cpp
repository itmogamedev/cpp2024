#include <iostream>

void collatz(int number) {

	if (number <= 0) {
		std::cout << "Collatz conjecture requires a natural number." << std::endl;
		return;
	}
	std::cout << "Collatz conjecture for your number: ";

	while (number != 1) {
		if (number % 2 == 0) {
			number /= 2;
		}
		else {
			number = number * 3 + 1;
		}
		std::cout << number << " ";
	}

}

int main()
{
	int number;
	std::cout << "Enter the starting number to your collatz conjecture: ";
	std::cin >> number;

	collatz(number);

}