#include <iostream>

int CheckSiracus(int number);

int main()
{
	setlocale(LC_ALL, "Russian");

	for (int i = 1; i < 10001; i++)
	{
		CheckSiracus(i);
	}
}

int CheckSiracus(int number)
{
	if (number == 1)
	{
		std::cout << "Гипотеза не нарушена" << std::endl;
	}
	else
	{
		if (number % 2 == 0)
		{
			number = number / 2;
		}
		else
		{
			number = (number * 3 + 1) / 2;
		}

		CheckSiracus(number);
	}

	return number;
}