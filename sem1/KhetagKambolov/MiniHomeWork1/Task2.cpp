#include <iostream>

double Trapezoid(double side1, double side2, double height)
{
	return (side1 + side2) * height / 2;
}

int main()
{
	double side1, side2, height;
	std::cout << "Enter the size of the first side: ";
	std::cin >> side1;
	std::cout << "Enter the size of the second side: ";
	std::cin >> side2;
	std::cout << "Enter the height: ";
	std::cin >> height;
	std::cout << Trapezoid(side1, side2, height);
}







