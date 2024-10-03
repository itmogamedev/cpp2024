#include <iostream>
#include <vector>

int digits[36];

void to_sys(int number, int base)
{
	if (base < 2 || base > 36)
	{
		std::cout << "Bad base value!" << std::endl;
		return;
	}

	std::cout << number << " in " << base << " base is ";

	std::vector<char> result;
	while (number != 0)
	{
		result.push_back(digits[number % base]);
		number /= base;
	}
	for (int i = result.size()-1; i >= 0; i--)
		std::cout << result[i];
	std::cout << std::endl;
}

void help()
{
	std::cout << "Hello, user! This program can convert numbers from dec system to another (from 2 to 36).\n"
	<< "You can run this commands:\n"
	<< "h - show this message\n" << "c - start converter\n" << "e - close program\n";
}

int main()
{
	help();

	for (int i = 0; i < 10; i++) digits[i] = '0' + i;
	for (int i = 10; i < 36; i++) digits[i] = 'A' - 10 + i;

	char command;
	int num, base;
	while (true)
	{
		std::cout << "Type command: ";
		std::cin >> command;

		switch (command)
		{
			case 'h':
				help();
				break;
			case 'c':
				std::cout << "Enter number (in dec sys): ";
				std::cin >> num;
				std::cout << "Enter base: ";
				std::cin >> base;
				to_sys(num, base);
				break;
			case 'e':
				return 0;
			default:
				std::cout << "Unknown command!" << std::endl;
		}
	}
}
