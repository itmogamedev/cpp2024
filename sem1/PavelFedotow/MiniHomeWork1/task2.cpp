#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	float UpperBase;
	float LowerBase;
	float Height;

	std::cout << "Укажите длину верхнего основания трапеции: ";
	std::cin >> UpperBase;

	std::cout << "Укажите длину нижнего основания трапеции: ";
	std::cin >> LowerBase;

	std::cout << "Укажите длину высоты трапеции: ";
	std::cin >> Height;

	std::cout << "Площадь вашей трапеции: " << (UpperBase + LowerBase) / 2 * Height;