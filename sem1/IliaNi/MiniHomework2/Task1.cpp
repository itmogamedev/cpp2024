#include <iostream>
#include <iomanip>

void TenToHex() {
	int x;
	std::cout << "������� ���� �����: ";
	std::cin >> x;
	std::cout << "0x" << std::hex << x << std::endl;

	return;
}

void TenToOct() {
	int x;
	std::cout << "������� ���� �����: ";
	std::cin >> x;
	std::cout << std::setbase(8) << x << std::endl;

	return;
}

int main() {

	setlocale(LC_ALL, "Russian");

	int choice;

	do {
		std::cout << "�������" << std::endl;
		std::cout << "1 - 16-������ �������" << std::endl;
		std::cout << "2 - 8-������ �������" << std::endl;
		std::cout << "3 - �����" << std::endl;
		std::cout << "�������� ��������: ";
		std::cin >> choice;

		if (choice == 3) {
			std::cout << "�� ����� �� ���������:(";
			break;
		}


		switch (choice) {
			case 1:
				std::cout << "�� ������� 16-������ �������" << std::endl;
				TenToHex();
				break;
			case 2:
				std::cout << "�� ������� 8-������ �������" << std::endl;
				TenToOct();
				break;
			default:
				std::cout << "�� ������� �� ������, � ��� ����� 3 ��������)" << std::endl;
		}

	} while (choice != 3);

	return 0;
}