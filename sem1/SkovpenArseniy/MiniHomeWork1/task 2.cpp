#include <iostream>

int main()
{
	setlocale(LC_ALL, "RU");
	int a, b, h, square;
	std::cout << "Введите наименьшее основание трапеции:";
	std::cin >> a;
	std::cout << "Введите наибольшее основание трапеции:";
	std::cin >> b;
	std::cout << "Введите высоту трапеции:";
	std::cin >> h;
	square = ((a + b) / 2) * h;
	std::cout << "Площадь равна : " << square;

	return 0;
}