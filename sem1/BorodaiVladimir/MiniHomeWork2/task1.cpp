

#include <iostream>

int main() {
	int numb; //linkin park
	int choose;

	std::cout << "Enter a number: ";
	std::cin >> numb;
	std::cout << "Choose convertion: " << std::endl;
	std::cout << "1. Oct(8)" << std::endl;
	std::cout << "2. Hex(16)" << std::endl;
	std::cout << "Enter your choice: ";
	std::cin >> choose;

	if (choose == 1) {
		std::cout << "Result: " << std::oct << numb;
	}
	else if (choose == 2) {
		std::cout << "Resault: " << std::hex << numb;
	}
	else {
		std::cout << "Choose 1 or 2!" ;
		}


}