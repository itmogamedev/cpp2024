#include <iostream>

int main()
{
	int n;
	std::cout << "Enter the number - ";
	std::cin >> n;
	int x;
	std::cout << "Enter the number system: 16 or 8 - ";
	std::cin >> x;
	if (x == 16) {
		std::cout << std::hex << n;
	}
	if (x == 8) {
		std::cout << std::oct << n;
	}
	if (x != 16 and x != 8) {
		std::cout << "we can't do anything(((";
	}
}
