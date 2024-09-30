#include <iostream>
#include <iomanip>

void TenToHex() {
	int x;
	std::cout << "Введите свое число: ";
	std::cin >> x;
	std::cout << "0x" << std::hex << x << std::endl;

	return;
}

void TenToOct() {
	int x;
	std::cout << "Введите свое число: ";
	std::cin >> x;
	std::cout << std::setbase(8) << x << std::endl;

	return;
}

int main() {

	setlocale(LC_ALL, "Russian");

	int choice;

	do {
		std::cout << "Менюшка" << std::endl;
		std::cout << "1 - 16-ричная система" << std::endl;
		std::cout << "2 - 8-ричная система" << std::endl;
		std::cout << "3 - Выход" << std::endl;
		std::cout << "Выберете действие: ";
		std::cin >> choice;

		if (choice == 3) {
			std::cout << "Вы вышли из программы:(";
			break;
		}


		switch (choice) {
			case 1:
				std::cout << "Вы выбрали 16-ричную систему" << std::endl;
				TenToHex();
				break;
			case 2:
				std::cout << "Вы выбрали 8-ричную систему" << std::endl;
				TenToOct();
				break;
			default:
				std::cout << "Вы кажется не поняли, у вас всего 3 варианта)" << std::endl;
		}

	} while (choice != 3);

	return 0;
}