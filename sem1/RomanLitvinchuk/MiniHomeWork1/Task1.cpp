#include <iostream>

float square(float side) {
	return side * side;
}

int main()
{
	float side = 0.0;
	std::cout << "Side length?" << std::endl;
	std::cin >> side;
	if (side >= 0.0) {
		std::cout << "Square = " << square(side);
	}
	else {
		std::cout << "Invalid value!";
	}
	return 0;
}