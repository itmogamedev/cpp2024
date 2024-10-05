#include <iostream>

int main()
{
	int x;
	std::cout << "Enter a number - ";
	std::cin >> x;
	int y = 0; 
	while (x > 0) {
		y = y * 10 + x % 10;
		x = x / 10;	
	}
	std::cout << y;
}
