#include<iostream>
int main() {
	setlocale(LC_ALL, "Russian");
	int number, digit=0;
	std::cout << "Введите число ";
	std::cin >> number;
	while (number > 0) {
		digit = digit * 10;
		digit = (number % 10)+digit;
		number = number / 10;
	}
	std::cout << digit;
}
