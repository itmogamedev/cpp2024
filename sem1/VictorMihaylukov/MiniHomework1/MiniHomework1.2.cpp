#include <iostream>
#include <string>

int func(std::string s1, std::string s2) {
	std::cout << "Введите длину ";
	std::cout << s1;
	std::cout << " трапеции:";
	int side = 0;
	std::cin >> side;
	while (side < 0) {
		std::cout << s2;
		std::cout << " трапеции не может быть меньше нуля\n";
		std::cout << "Введите длину ";
		std::cout << s1;
		std::cout << " трапеции:";
		std::cin >> side;
	}
	return side;
}

int main() {
	setlocale(LC_ALL, "rus");

	int side1 = func("верхнего основания", "Сторона");
	int side2 = func("нижнего основания", "Сторона");
	int h = func("высоты", "Высота");

	std::cout << (side1 + side2) / 2 * h;
}
