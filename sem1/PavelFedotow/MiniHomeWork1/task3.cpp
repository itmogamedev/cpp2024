#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int numberOfElements;
	int firstNumber = 0;
	int secondNumber = 1;
	int currentNumber;
	while (true) 
	{

	std::cout << "Введите желаемое число элементов ряда Фибоначчи: ";
	std::cin >> numberOfElements;

	if (numberOfElements <= 0)
		std::cout << "Неверное число элементов :(" << std::endl;
	else 
	{
	std::cout << "Ваш ряд: " << 1 << " ";
	for (int x = 0; x < numberOfElements - 1; ++x) 
	{
		currentNumber = firstNumber + secondNumber;
		firstNumber = secondNumber;
		secondNumber = currentNumber;
		std::cout << currentNumber << " ";
	}
	break;
	}
	}
}