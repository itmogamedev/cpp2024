#include <iostream>
#include <iomanip>

void TenToHex() {
	int x;
	std::cin >> x;
	std::cout << "0x" << std::hex << x << std::endl;

	return;
}

void TenToOct() {
	int x;
	std::cin >> x;
	std::cout << std::setbase(8) << x << std::endl;

	return;
}

int main() {

	setlocale(LC_ALL, "Russian");

	int choice;

	do {
		std::cout << "Menu" << std::endl;
		std::cout << "2 - Hex" << std::endl;
		std::cout << "2 - Oct" << std::endl;
		std::cout << "3 - Exit" << std::endl;
		std::cout << "Select an action: ";
		std::cin >> choice;

		if (choice == 3) {
			std::cout << ":(";
			break;
		}


		switch (choice) {
			case 1:
				TenToHex();
				break;
			case 2:
				TenToOct();
				break;
			default:
				std::cout << "You have only 3 option)" << std::endl;
		}

	} while (choice != 3);

	return 0;
}
