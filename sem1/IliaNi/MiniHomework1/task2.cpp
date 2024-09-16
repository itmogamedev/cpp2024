#include <iostream>

int first_base = 0;
int second_base = 0;
int trapezoid_area = 0;
int height = 0;
int main() {
	std::cout << "Enter the first base of the trapezoid: ";
	std::cin >> first_base;
	std::cout << "Enter the second base of the trapezoid: ";
	std::cin >> second_base;
	std::cout << "Enter the height of the trapezoid: ";
	std::cin >> height;
	trapezoid_area = (first_base + second_base) * height / 2;
	std::cout << trapezoid_area;
	return 0;
}