#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	int chosenNumber;
	int reversedNumber = 0;

	std::cout << "Введите ваше число: ";
	std::cin >> chosenNumber;

	while (chosenNumber) 
	{
		reversedNumber = reversedNumber * 10 + chosenNumber % 10;
		chosenNumber /= 10;
	}
	
	std::cout << "Развернутое число: " << reversedNumber;
}