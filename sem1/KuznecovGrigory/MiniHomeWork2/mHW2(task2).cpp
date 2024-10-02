#include <iostream>
int main()
{
	setlocale(LC_ALL, "Russian");
	int number;
	std::cout << "Введите любое натуральное число кроме 0 и 1" << '\n';
	std::cin >> number;
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
	}
	std::cout << "Гипотеза подтверждена";

}