#include <iostream>
//task 2
int main() {
	setlocale(LC_ALL, "RU");
	std::cout << "input an natural number:" << "\n";
	int number;
	std::cin >> number;
	while (number != 1) {
		std::cout << "Your number:" <<number<< "\n";
		if (number % 2 == 0) {
			std::cout << "is even" << "\n";
			number /= 2;
			std::cout << "new number:" << number << "\n";
		}
		else {
			std::cout << "is odd" << "\n";
			number = (number * 3 + 1) / 2;
			std::cout << "new number:" << number << "\n";

		}
	}
	std::cout << "an 1 achived. hypothesis proved."<<"\n";
	return 0;
}
