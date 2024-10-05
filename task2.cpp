#include <iostream>
//задание 2
int main() {
	setlocale(LC_ALL, "RU");
	std::cout << "¬ведите натуральное число:" << "\n";
	int number;
	std::cin >> number;
	while (number != 1) {
		std::cout << "¬аше число:" <<number<< "\n";
		if (number % 2 == 0) {
			std::cout << "оно чЄтно" << "\n";
			number /= 2;
			std::cout << "новое число:" << number << "\n";
		}
		else {
			std::cout << "оно нечЄтно" << "\n";
			number = (number * 3 + 1) / 2;
			std::cout << "новое число:" << number << "\n";

		}
	}
	std::cout << "еденица получена, гипотеза доказана"<<"\n";
	return 0;
}