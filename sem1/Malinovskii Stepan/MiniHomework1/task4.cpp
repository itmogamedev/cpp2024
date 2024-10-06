#include <iostream>

void reverser(int number)
{
	while (number>0)
	{
		std::cout << number % 10;
		number /= 10;
	}
}

int main()
{
	setlocale(LC_ALL, "");

	int inputNumber = 0;

	std::cout << "¬ведите ваше число: ";
	std::cin >> inputNumber;

	reverser(inputNumber);
	
	return 0;
}

