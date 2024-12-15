#include <iostream>
int FibonacciElements(int FirstElement, int PreviousElement)
{
	int NextElement;
	NextElement = FirstElement + PreviousElement;
	return NextElement;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int NumberOfElements, PreviousElement1 = 1, PreviousElement2 = 1, a = 0;
	std::cout << "Введите колличество элементов ряда Фибоначи:";
	std::cin >> NumberOfElements;
	if (NumberOfElements > 0)
	{
		std::cout << 1 << ", ";
		NumberOfElements -= 1;
		std::cout << 1 << ", ";
		NumberOfElements -= 1;
		while (NumberOfElements > 0)
		{
			std::cout << FibonacciElements(PreviousElement1, PreviousElement2) << ", ";
			a = PreviousElement2;
			PreviousElement2 = FibonacciElements(PreviousElement1, PreviousElement2);
			PreviousElement1 = a;
			NumberOfElements -= 1;
		}
	}
	else
	{
		if (NumberOfElements < 0)
		{
			std::cout << "Вы ввели число меньше 0";
			return 0;
		}
	}
	return 0;
}