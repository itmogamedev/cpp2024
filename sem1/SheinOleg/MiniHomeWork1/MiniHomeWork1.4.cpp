#include <iostream>

int FlipNumber(int a)
{
	int b = 0;
	while (a)
	{
		b = b * 10 + a % 10;
		a /= 10;
	}
	return b;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		int a = 0;
		std::cout << "Введите число. чтобы его перевернуть: ";
		std::cin >> a;
		if (a > 9)
		{
			std::cout << "Перевёрнутое число: ";
			std::cout << FlipNumber(a) << std::endl;
		}
		else
		{
			std::cout << "Для такого значения невозможно найти перевёрнутое число. Пожалуйста, введите положительное целое число больше 9" << std::endl;
		}
	}
}