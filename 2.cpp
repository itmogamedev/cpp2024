#include <iostream>

int main() {
	
	setlocale(LC_ALL, "RU");
	int a;
	int b;
	int h;
	std::cout << "������� ������� �������:";
	std::cin >> a ;
	std::cout << "������� ������ �������:";
	std::cin >> b;
	std::cout << "������� ������:";
	std::cin >> h;
	std::cout << "������� �����:" << ((a + b) / 2) * h;

	
	return 0;
}