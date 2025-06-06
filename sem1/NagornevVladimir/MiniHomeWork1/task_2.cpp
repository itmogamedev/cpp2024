#include <iostream>

float func_area_trapeze(float a, float b, float c) {
	std::cout << "Area trapeze = " << (a + b) / 2 * c;
	return 1;
}

int main() {
	float side_1, side_2, hight;
	std::cout << "Enter first side: ";
	std::cin >> side_1;
	std::cout << "Enter second side: ";
	std::cin >> side_2;
	std::cout << "Enter hight: ";
	std::cin >> hight;
	func_area_trapeze(side_1, side_2, hight);
}
