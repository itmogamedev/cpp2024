#include <iostream>
//задание 1
int main() {
	setlocale(LC_ALL, "RU");
	std::cout << "Введите число:" << "\n";
	int number;
	std::cin >> number;
	std::cout << "Ваше число в 16-ричной системе:" << "\n";
	std::cout << std::hex << number << "\n";
	std::cout << "Ваше число в 8-ричной системе:" << "\n";
	std::cout << std::oct << number << "\n";
	return 0;

}