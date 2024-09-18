#include <iostream>

int main() {
	int a = 0, b = 1, l = 0, c = 0;
	std::cout << "Input number cicle: ";
	std::cin >> l;
	std::cout << 1 << " ";
	for (int i = l; i > 0; --i) {
		c = a + b;
		a = b;
		b = c;

		std::cout << c << " ";
	}

}