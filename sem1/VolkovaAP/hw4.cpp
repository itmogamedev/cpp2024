#include <iostream>

int main() {
	int k = 0;
	int n;
	std::cin >> n;
	while (n != 0) {
		k = k * 10 + n % 10;
		n = n / 10;
	}
	std::cout << k;
}