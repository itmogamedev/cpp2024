
#include <iostream>

double TrapezoidArea(double upSide, double downSide, double height);

int main()
{
	setlocale(LC_ALL, "RU");
	double upSide, downSide, height;
	std::cout << "Введите размер верхнего основания трапеции: ";
	std::cin >> upSide;
	std::cout << "Введите размер нижнего основания трапеции: ";
	std::cin >> downSide;
	std::cout << "Введите размер высоты трапеции: ";
	std::cin >> height;
	double trapezoidArea = TrapezoidArea(upSide,downSide,height);
	std::cout << "Площадь трапеции равна: " << trapezoidArea;
	return 0;
}

double TrapezoidArea(double upSide, double downSide, double height)
{
	return (upSide + downSide)/2 * height;
}


