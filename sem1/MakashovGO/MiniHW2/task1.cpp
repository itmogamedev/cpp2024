#include <iostream>
#include <string>

std::string numsys16()
{
	int num;
	std::cout << "Enter number: ";
	std::cin >> num;
	std::string val = "0123456789ABCDEF";
	std::string a = "";
	while (num != 0)
	{
		a = val[num % 16] + a;
		num /= 16;
	}
	return a;
}

std::string numsys8()
{
	int num;
	std::cout << "Enter number: ";
	std::cin >> num;
	std::string a = "";
	while (num != 0)
	{
		a = std::to_string(num % 8) + a;
		num /= 8;
	}
	return a;
}


int main()
{
	printf("Functions:\n"
		"1. conversion to the octal numsys\n"
		"2. conversion to hexadecimal numsys\n");
	std::cout << "Choose one of the suggested option (enter number): ";
	int n;
	std::cin >> n;
	switch (n)
	{
	case (1):
		std::cout << numsys8();
		break;
	case (2):
		std::cout << numsys16();
		break;
	default:
		std::cout << "select a function only from the suggested ones";
		break;
	}
}