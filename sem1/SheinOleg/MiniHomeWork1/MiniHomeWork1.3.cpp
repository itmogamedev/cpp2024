#include <iostream>

long int FiboCalc(int x)
{
	if (x >= 2)
	{
		return FiboCalc(x - 1) + FiboCalc(x - 2);
	}
	else if (x == 1)
	{
		return 1;
	}
	else if (x == 0)
	{
		return 0;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		int a = 0;
		std::cout << "Введите значение для подсчёта числа Фибоначчи: ";
		std::cin >> a;
		if (a > 0)
		{
			std::cout << "Последовательность чисел Фибоначчи: ";
			for (int i = 0; i < a; i++)
			{
				std::cout << FiboCalc(i);
				if (i + 1 == a)
					std::cout << std::endl;
				else
					std::cout << ", ";
			}
		}
		else
		{
			std::cout << "Для такого значения невозможно найти числа Фибоначчи. Пожалуйста, введите положительное целое число." << std::endl;
		}
	}
}