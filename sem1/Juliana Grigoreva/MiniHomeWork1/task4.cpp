#include <iostream>

int main() {
	int n; int b = 0;
	std::cin >> n;
	while (n > 0) {
		b *= 10;
		b += n % 10;
		n /= 10;
	}
	std::cout << b;
}