#include <iostream>

double Square(double side)
{
	return side * side;
}

int main()
{
	double input;
	std::cout << "Enter the size of a square: ";
	std::cin >> input;
	std::cout << Square(input);
}







