#include <iostream>

float AreaOfSquare(float a, float b, float h)
{
	return (a + b) / 2 * h;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		float a = 0;
		float b = 0;
		float h = 0;
		std::cout << "Введите длину первого основания трапеции: ";
		std::cin >> a;
		std::cout << "Введите длину второго основания трапеции: ";
		std::cin >> b;
		std::cout << "Введите длину высоты трапеции: ";
		std::cin >> h;
		if (a > 0 && b > 0 && h > 0)
		{
			std::cout << "Площадь трапеции: ";
			std::cout << AreaOfSquare(a, b, h) << std::endl;
		}
		else
		{
			std::cout << "Для таких значений невозможно найти площадь. Пожалуйста, вводите положительные целые числа." << std::endl;
		}
	}
}