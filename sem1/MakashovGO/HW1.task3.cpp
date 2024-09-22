#include <iostream>

int main()
{
	int n, a = 0, b = 1;
	std::cout << "Enter the number of members of the fibonacci series: ";
	std::cin >> n;
	while (n != 0)
	{
		std::cout << a << ' ';
		b += a;
		a = b - a;
		n--;
	}
}