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

	int n;
	std::cout << "Enter a number greater than zero): ";
	std::cin >> n;

	if (n <= 0) {
		std::cout << "'Greater than zero' means nothing to you??";
	}
	else {
		Sirakuz(n);
	}
	return 0;
}
