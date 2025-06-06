#include <iostream>

double trapArea() {
	double first_base, second_base, height, result;
	std::cout << "Enter the first base of a trapezoid: " << std::endl;
	std::cin >> first_base;
	std::cout << "Enter the second base of a trapezoid: " << std::endl;
	std::cin >> second_base;
	std::cout << "Enter the height of a trapezoid: " << std::endl;
	std::cin >> height;
	result = (first_base + second_base) / 2 * height;
	std::cout << "Area of a trapezoid: " << std::endl << (first_base + second_base) / 2 * height;
}

int main() {
	trapArea();
}