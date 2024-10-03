#include <iostream>

double sqrArea() {
	double side;
	double result;
	std::cout << "Enter side of square length:" << std::endl;
	std::cin >> side;
	result = side * side;
	std::cout << "Area of square:" << std::endl << result << std::endl;
	return result;
}

int main() {
	sqrArea();
}