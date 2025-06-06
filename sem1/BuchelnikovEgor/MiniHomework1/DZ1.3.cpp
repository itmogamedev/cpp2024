#include <iostream>
int main() {
	setlocale(LC_ALL, "Russian");
	int variable1 = 0, variable2 = 1, variable3;
	while (true) {
		int N;
		std::cout << "Введите колличество элементов ряда Фиббоначи ";
	std::cin >> N;
	if (N == 0) {
		std::cout << "0";
		break;
	}

	for (int i=0; i < N; i++) {
		variable3 = variable1 + variable2;
		std::cout << variable3 << " " << std::endl;
		variable1 = variable2;
		variable2 = variable3;
	}
	 break;
	}
}
