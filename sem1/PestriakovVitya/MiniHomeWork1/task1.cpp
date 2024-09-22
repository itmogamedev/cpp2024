#include <iostream>

float area_square(float side) {
	return side * side;
}

 float main() { // Площадь квадрата
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите одну из сторон квадрата:" << std::endl;
	int side;
	std::cin >> side;
	std::cout << area_square(side) << std::endl;
	return 0;
}
