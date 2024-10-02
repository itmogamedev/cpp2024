#include <iostream>
int TrapezoidArea(int basis1, int basis2, int height)
{
	return (basis1 + basis2) * height / 2;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int TrapezoidSide1, TrapezoidSide2, TrapezoidHeight;
	std::cout << "Введите длину оснований и высоту трапеции:";
	std::cin >> TrapezoidSide1 >> TrapezoidSide2 >> TrapezoidHeight;
	std::cout << "Площадь трапеции:" << TrapezoidArea(TrapezoidSide1, TrapezoidSide2, TrapezoidHeight) << '\n';
	return 0;
}