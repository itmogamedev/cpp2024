#include <iostream>
int SquareArea(int SideSize)
{
	return SideSize * SideSize;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int SquareSide;
	std::cout << "Введите сторону квадрата:";
	std::cin >> SquareSide;
	std::cout << "Площадь квадрата:" << SquareArea(SquareSide) << '\n';
	return 0;
}