#include <iostream>

int reverse_numb(int numb) {
	int result = 0;
	while (true) {
		result = result * 10 + (numb % 10);
		numb = numb / 10;
		if (numb == 0) {
			return result;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int input;
	std::cout << "Введите число: ";
	std::cin >> input;
	std::cout << "Ваше число перевернуто: " << reverse_numb(input);
}
