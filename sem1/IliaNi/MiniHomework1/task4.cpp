#include <iostream>

int main() {
	int a;
	int i = 0;
	std::cout << "Enter a number: ";
	std::cin >> a;
	while (a) {
		i = a % 10 + i * 10;
		a /= 10;
	}
	std::cout << i;
	return 0;
}

