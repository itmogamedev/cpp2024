#include <iostream>

int main() {
	int num;
	int choice;

	std::cout << "Enter a decimal number: ";
	std::cin >> num;
	std::cout << "Choose convertion: " << std::endl;
	std::cout << "1. Octal" << std::endl;
	std::cout << "2. Hexademical" << std::endl;
	std::cout << "Enter your choice (1 or 2): " << std::endl;
	std::cin >> choice;

	if (choice == 1) {
		std::cout << "Octal number: " << std::oct << num << std::endl;
	}
	else if (choice == 2) {
		std::cout << "Hexademical number: " << std::hex << num << std::endl;
	}
	else {
		std::cout << "Invalid input!" << std::endl;
	}

	return 0;
}

