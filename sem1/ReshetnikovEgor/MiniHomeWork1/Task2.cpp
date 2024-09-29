#include <iostream>

int Trapez(int base1, int base2, int height) {
	return (base1 + base2) / 2 * height;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int input_1, input_2, input_3;
	td::cout << "Введите нижнее и верхнее основание трапеции: ";
	std::cin >>  input_1 >> input_2;
	std::cout << "Введите высоту трапеции: ";
	std::cin >>  input_3;
	std::cout <<  "Площадь трапеции равна: " << Trapez(input_1, input_2, input_3) << std::endl;
}
