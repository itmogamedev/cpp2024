#include <iostream>
//������� 2
int main() {
	std::cout << "������� ������ ���������: \n";
	float base1;
	std::cin >> base1;
	std::cout << "�������: \n";
	float base2;
	std::cin >> base2;
	std::cout << "� ������ \n";
	float height;
	std::cin >> height;
	std::cout << (base1 + base2);
	std::cout << "\n";
	std::cout << (base1 + base2) / 2;
	std::cout << "\n";
	return (base1 + base2) / 2 * height;
	return 0;
}