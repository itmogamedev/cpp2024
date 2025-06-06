#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		long long int number = 0;
		std::cout << "Введите любое натуральное число для проверки гипотезы Сиракуз: ";
		std::cin >> number;
		if (number > 0)
		{
			while (number != 1)
			{
				if (number % 2 == 0)
				{
					number /= 2;
				}
				else
				{
					number = (number * 3 + 1) / 2;
				}
				std::cout << number << std::endl;
			}
			std::cout << "Гипотеза доказана" << std::endl;
		}
		else
		{
			std::cout << "Ошибка. Введите положительное число";
		}
	}
}