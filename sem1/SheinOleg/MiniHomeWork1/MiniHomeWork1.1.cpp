#include <iostream>

int AreaOfSquare(int a)
{
	return a * a;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		int a = 0;
		std::cout << "Введите длину стороны квадрата: ";
		std::cin >> a;
		if (a > 0)
		{
			std::cout << "Площадь квадрата: ";
			std::cout << AreaOfSquare(a) << std::endl;
		}
		else
		{
			std::cout << "Для такой стороны квадрата невозможно найти площадь. Пожалуйста, введите положительное целое число." << std::endl;
		}
	}
}