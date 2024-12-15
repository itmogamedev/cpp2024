#include <iostream>
int main()
{
	int number, rev = 0, rem;
	std::cout << "Enter number:\n";
	std::cin >> number;
	while (number > 0)
	{
		rem = number % 10;
		rev = rem + rev * 10;
		number /= 10;
	}
	std::cout << rev;
}