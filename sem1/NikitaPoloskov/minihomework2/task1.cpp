#include <iostream>
#include <string>

void to_sys(int number, int base)
{
	if (base < 2 || base > 36)
	{
		std::cout << "Bad base value!" << std::endl;
		return;
	}

	std::cout << number << " in " << base << " base is ";

	std::string result = "";
	while (number != 0)
	{
		result = std::to_string(number % base) + result;
		number /= base;
	}

	std::cout << result << std::endl;
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
