#include <iostream>

int func_area_square(int a, int b) {
	std::cout << "Area square = " << a * b;
	return a * b;
}

int main() {
	int side_1, side_2;
	std::cout << "Enter first side: ";
	std::cin >> side_1;
	std::cout << "Enter second side: ";
	std::cin >> side_2;
	func_area_square(side_1, side_2);
}