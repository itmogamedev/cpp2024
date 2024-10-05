#include <iostream>

int main() {
	int n; int i; int a = 0; int b = 1; int c;
	std::cin >> n;
	std::cout << a << " " << b << " ";
	while (i < (n - 2)) {
		i++;
		c = a + b;
		a = b;
		b = c;
		std::cout << c << " ";
	}
}