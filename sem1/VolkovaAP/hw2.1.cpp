#include <iostream>

int main() {
	int number;
	std::cin >> number;
	std::cout << "oct = " << std::oct << number << '\n';
	std::cout << "hex = " << std::hex << number;
}