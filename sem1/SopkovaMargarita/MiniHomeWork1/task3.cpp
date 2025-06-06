#include <iostream>

int main() {
	int N = 0;
	int counter = 0;
	int number1 = 0;
	int number2 = 1;
	int temporary = 0;
	std::cout << "Enter the number";
	std::cin >> N;
	while (true) {
		if (N > counter and counter > 0) {
			counter++;
			std::cout << number1 + number2 << " ";
			temporary = number1;
			number1 = number2;
			number2 = number1 + temporary;
		}
		if (counter == 0) {
			counter++;
			std::cout << "0 ";
		}
		if (N < counter) {
			return 0;
		}
	}
	return 0;
}

