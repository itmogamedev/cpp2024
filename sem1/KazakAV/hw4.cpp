#include <iostream>

int main() {
	int n;
	std::cin >> n;
	while (n > 0) {
		int n1 = n % 10;
		n = n / 10;
		std::cout << n1;
	}
}
