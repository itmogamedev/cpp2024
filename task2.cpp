#include <iostream>
//������� 2
int main() {
	setlocale(LC_ALL, "RU");
	std::cout << "������� ����������� �����:" << "\n";
	int number;
	std::cin >> number;
	while (number != 1) {
		std::cout << "���� �����:" <<number<< "\n";
		if (number % 2 == 0) {
			std::cout << "��� �����" << "\n";
			number /= 2;
			std::cout << "����� �����:" << number << "\n";
		}
		else {
			std::cout << "��� �������" << "\n";
			number = (number * 3 + 1) / 2;
			std::cout << "����� �����:" << number << "\n";

		}
	}
	std::cout << "������� ��������, �������� ��������"<<"\n";
	return 0;
}