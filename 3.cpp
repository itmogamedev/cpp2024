#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	int i;
	int a = 0;
	int b = 1;
	int c;
	std::cout << "¬ведите колличество желаемых значений:";
	std::cin >> n;
	if (n <= 1 and n != 0) {
		std::cout << 0 << " ";
	}
	if (n > 1) {
		std::cout << 0 << " " << 1 << " ";
	}
	for (i = 0; i < n - 2; ++i) {
		c = a + b;
		a = b;
		b = c;
		std::cout << c << " ";
	}

	return 0;
}