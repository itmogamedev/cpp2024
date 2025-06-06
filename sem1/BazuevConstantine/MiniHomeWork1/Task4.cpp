#include "iostream"

int Reverse(int num);

int main()
{
	int number;
	std::cout << "Enter a number: ";
	std::cin >> number;
	std::cout << "Reverse number is " << Reverse(number);
}

int Reverse(int num)
{
	int res = 0;

	while (num != 0)
	{
		res *= 10;
		res += num % 10;
		num = num / 10;
	}

	return res;
}