#include <iostream>


int main()
{
	int n;
	std::cout << "to test the hypothesis, enter a number: ";
	std::cin >> n;
	if (n <= 0)
	{
		std::cout << "The number must be natural";
	}
	else
	{
		std::cout << n << ' ';
		while (n != 1)
		{
			if (n % 2 == 0)
			{
				n /= 2; std::cout << n << ' ';
			}
			else
			{
				n = (3 * n + 1) / 2; std::cout << n << ' ';
			}
		}
	}
}