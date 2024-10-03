#include <iostream>

int main() {
	while (true) {
		int selection;
		std::cout << "Select mode:" << std::endl << "1 - decimal to octal" << std::endl << "2 - decimal to hexadecimal" << std::endl << "3 - exit" << std::endl;
		std::cin >> selection;
		if (selection != 1 and selection != 2 and selection != 3) {
			std::cout << "Wrong selection" << std::endl;
			break;
		}

		switch (selection) {
		case 1: {
			int number;
			std::cout << "Enter number to convert:" << std::endl;
			std::cin >> number;
			std::cout << "Result:" << std::endl << std::oct << number << std::endl << std::endl;
			break;
		}
		case 2: {
			int number;
			std::cout << "Enter number to convert:" << std::endl;
			std::cin >> number;
			std::cout << "Result:" << std::endl << std::hex << number << std::endl << std::endl;
			break;
		}
		case 3: {
			return 0;
		}
		}
	}
}