#include <iostream>
int main() {
	setlocale(LC_ALL, "Russian");
	int Переменная1 = 0, Переменная2 = 1, Переменная3;
	while (true) {
		int N;
		std::cout << "Введите колличество элементов ряда Фиббоначи ";
	std::cin >> N;
	if (N == 0) {
		std::cout << "0";
		break;
	}

	for (int i=0; i < N; i++) {
		Переменная3 = Переменная1 + Переменная2;
		std::cout << Переменная3 << " " << std::endl;
		Переменная1 = Переменная2;
		Переменная2 = Переменная3;
	}
	 break;
	}
}