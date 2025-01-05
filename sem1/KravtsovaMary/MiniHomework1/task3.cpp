#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int a1 = 0;
	int a2 = 1;
	for (int i = 0; i < n; i++) {
		std::cout << a1 << ' ';
		a1 = a1 + a2;
		a2 = a1 - a2;
	}
}