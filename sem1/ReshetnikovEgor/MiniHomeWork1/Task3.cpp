#include <iostream>

void Fibonachi(int last_numb) {
	int rememb_numbers[3]{ 0, 1, 1 };
	for (int i = 0; i < last_numb; i++) {
		std::cout << rememb_numbers[0] << ' ';
		rememb_numbers[2] = rememb_numbers[1];
		rememb_numbers[1] = rememb_numbers[0] + rememb_numbers[1];
		rememb_numbers[0] = rememb_numbers[2];
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	int numb_fibon;
	std::cout << "Введите число для последовательности фибоначи: ";
	std::cin >> numb_fibon;
	std::cout << "Последовательнось: ";
	Fibonachi(numb_fibon);
}
