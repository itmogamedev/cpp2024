#include <iostream>

float trapezoidArea(float base1, float base2, float height) {
	return (base1 + base2) / 2 * height;
}

int main()
{
	std::cout << "Enter base 1, base 2 and height in the appropriate order: ";

	float base1{};
	float base2{};
	float height{};
	std::cin >> base1 >> base2 >> height;

	std::cout << "The area of a trapezoid: " << trapezoidArea(base1, base2, height);
}
