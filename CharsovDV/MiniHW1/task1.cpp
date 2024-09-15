#include <iostream>


float squareArea(float sideSquare) {
	return sideSquare * sideSquare;
}


int main()
{
	std::cout << "Input the length of a side of a square: ";

	float sideSquare{};
	std::cin >> sideSquare;

	std::cout << "The area of a square: " << squareArea(sideSquare);
}