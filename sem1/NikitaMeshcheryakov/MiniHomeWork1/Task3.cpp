#include <iostream>

void PrintFibNum(int num);

int main()
{
	setlocale(LC_ALL, "RU");
	int userInput;
	std::cout << "Сколько чисел Фибоначчи вывести?: ";
	std::cin >> userInput;
	PrintFibNum(userInput);
	return 0;
}

void PrintFibNum(int num)
{
	long long int fib1 = 0;
	long long int fib2 = 1;
	long long int temp = 0;
	for (int i = 0; i < num; ++i)
	{
		std::cout << fib1 << "  ";
		temp = fib1;
		fib1 = fib2;
		fib2 = temp + fib1;
	}
}

