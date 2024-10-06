#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		long long int number = 0;
		std::cout << "Введите число для перевода: ";
		std::cin >> number;
		if (number >= 0)
		{
			std::cout << "Число в восьмиричной системе: " << std::oct << number << std::endl;
			std::cout << "Число в шестнадцатеричной системе: " << std::hex << number << std::endl << std::endl;
		}
		else
		{
			std::cout << "Ошибка. Введите положительное число или 0";
		}
	}
}