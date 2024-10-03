#include <iostream>

int main()
{
	float a;
	float b;
	float h;
	std::cout << "Enter the top side";
	std::cin >> a;
	std::cout << "Enter the underside";
	std::cin >> b;
	std::cout << "Enter the height";
	std::cin >> h;
	std::cout << ((a + b) / 2) * h;
}