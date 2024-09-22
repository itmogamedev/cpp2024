#include <iostream>

float SquareTrapezoid(float side1, float side2, float height) {
	return (side1 + side2) / 2 * height;
}


int main()
{
	float side1, side2 = 0.0, height = 0.0;

	std::cout << "Sides length?" << std::endl;
	std::cin >> side1;
	std::cin >> side2;
	std::cout << "Height?" << std::endl;
	std::cin >> height;
	if (side1 >=0 and side2>=0 and height>=0) {
		std::cout << "Square = " << SquareTrapezoid(side1, side2, height);
	}
	else {
		std::cout << "Invalid value";
	}
	return 0;
}