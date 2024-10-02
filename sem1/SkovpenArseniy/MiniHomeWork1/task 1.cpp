#include <iostream>

int main()
{
	setlocale(LC_ALL, "RU");
	int side, square;
	std::cout << "Введите сторону квадрата:";
	std::cin >> side;
	square= pow(side, 2);
	std::cout << "Площадь равна : " << square;



	return 0;
}


