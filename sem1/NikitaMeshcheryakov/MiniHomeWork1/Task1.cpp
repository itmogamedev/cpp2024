#include <iostream>

double SquareArea(double squareSide);

int main()
{
	setlocale(LC_ALL, "RU");
	double squareSide;
	std::cout << "¬ведите размер стороны квадрата: ";
	std::cin >> squareSide;
	double squareArea = SquareArea(squareSide);
	std::cout << "ѕлощадь квадрата равна: " << squareArea;
	return 0;
}

double SquareArea(double squareSide)
{
	return squareSide * squareSide;
}