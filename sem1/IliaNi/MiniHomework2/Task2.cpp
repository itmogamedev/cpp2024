#include <iostream>

void Sirakuz(int n) {
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = n * 3 + 1;
		}
		std::cout << n << std::endl;
	}
}

int main() {

	setlocale(LC_ALL, "Russian");

	int n;
	std::cout << "¬ведите число больше нул€): ";
	std::cin >> n;

	if (n <= 0) {
		std::cout << "ѕоросил же, ЅќЋ№Ў≈ Ќ”Ћя!!!";
	}
	else {
		Sirakuz(n);
	}
	return 0;
}