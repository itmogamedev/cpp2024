#include <iostream>
//задание 3
int main() {
	setlocale(LC_ALL, "RU");
	std::cout << "Введите необходимое количество чисел:";
	int count;
	int fib1 = 1;
	int fib2 = 0;
	std::cin >> count;
	for (int i = 0; i < count; i++) {
		if (i % 2 == 0) {
			std::cout << fib1 << "; ";
			fib2 = fib1 + fib2;
		}
		else {
			std::cout << fib2 << "; ";
			fib1 = fib1 + fib2;
		}

	}
	return 0;
}
