#include <iostream>

int main() {
	setlocale(LC_ALL, "rus");
	std::cout << "Введите сторону квадрата:";
	int side = 0;
	std::cin >> side;
	while (side < 0) {
		std::cout << "Сторона квадрата не может быть меньше 0\n";
		std::cout << "Введите сторону квадрата:";
		std::cin >> side;
	};
	std::cout << "\n";
	std::cout << pow(side, 2);
}