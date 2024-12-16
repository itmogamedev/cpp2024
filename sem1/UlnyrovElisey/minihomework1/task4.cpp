#include <iostream>
int main()
{
	int x;
	std::cout << "Enter the number: ";
	std::cin >> x;
	
	while ( x != 0)
	{
		int y = x % 10;
		x = x / 10;
		std::cout << y;
	}
	return 0;
}