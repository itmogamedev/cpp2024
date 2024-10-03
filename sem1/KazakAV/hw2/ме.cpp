#include <iostream>
int main() {
	int number = 0;
	std::cin >> number;
	std::cout << std::oct << number << " - octal number notation" << std::endl;
	std::cout << std::hex << number << " - hexadecimal number notation";
}