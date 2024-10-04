#include "iostream"

void Cirakuz(int num);

int main()
{
	int number;
	std::cout << "Enter a natural number: ";
	std::cin >> number;

	while (number <= 0)
	{
		std::cout << "Enter a valid NATURAL number: ";
		std::cin >> number;
	}

	Cirakuz(number);

}

void Cirakuz(int num)
{
	while (num > 1)
	{
		if (num % 2 == 0)
		{
			num = num / 2;
		}
		else
		{
			num = ((num * 3) + 1) / 2;
		}

		std::cout << "Current number is " << num << std::endl;

	}

	if (num == 1)
	{
		std::cout << "proven" << std::endl;
	}
	else
	{
		std::cout << "disproved" << std::endl;
	}
}