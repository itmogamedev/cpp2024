#include <iostream>

int main() {
	int num;
	std::cout << "Enter a natural number: ";
	std::cin >> num;

	if (num < 1) {
		std::cout << "Please enter a positive integer greater than zero: ";
		std::cin >> num;
	}

	while (num != 1) {
		if (num % 2 == 0) {
			num /= 2;
			std::cout << num << " ";
		} 
		else {
			num = (num * 3 + 1) / 2;
			std::cout << num << " ";
		}
	}
	std::cout << "" << std::endl;

	if (num == 1) {
		std::cout << "Hypothesis is true!" << std::endl;
	}
	else {
		std::cout << "Hypothesis is false!" << std::endl;
	}

	return 0;
}