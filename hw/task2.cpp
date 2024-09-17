#include <iostream>
//задание 2
int main() {
	std::cout << "введите длинну основания: \n";
	float base1;
	std::cin >> base1;
	std::cout << "второго: \n";
	float base2;
	std::cin >> base2;
	std::cout << "и высоту \n";
	float height;
	std::cin >> height;
	std::cout << (base1 + base2);
	std::cout << "\n";
	std::cout << (base1 + base2) / 2;
	std::cout << "\n";
	return (base1 + base2) / 2 * height;
	return 0;
}