#include <iostream>
//задание 1
int main() {
	setlocale(LC_ALL, "RU");
	std::cout << "Введите длинну стороны квадрата";
	float side;
	std::cin >> side;
	std::cout << side * side;
	return 0;
}