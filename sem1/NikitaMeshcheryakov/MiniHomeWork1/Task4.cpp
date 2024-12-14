#include <iostream>

int main ()
{
	setlocale(LC_ALL, "RU");
	long long int userInput;
	long long int transformedNumber = 0;
	int num = 0;
	std::cout << "Введите число, которое хотите преобразовать: ";
	std::cin >> userInput;
	while(userInput > 0)
	{
		num = userInput % 10;
		userInput = (userInput - num)/10;
		transformedNumber = transformedNumber * 10 + num;
	}
	std::cout << "Преобразованное число: " << transformedNumber;
}

/* Вывод числа с нулями в начале:

int main()
{
	setlocale(LC_ALL, "RU");
	long long int userInput;
	long long int transformedNumber = 0;
	int num = 0;
	std::cout << "Введите число, которое хотите преобразовать: ";
	std::cin >> userInput;
	std::cout << "Преобразованное число: ";
	while (userInput > 0)
	{
		num = userInput % 10;
		userInput = (userInput - num) / 10;
		std::cout << num;
	}
}

*/
