#include <iostream>

int main() {
	int n1 = 0;
	int n2 = 1;
	int k;
	std::cin >> k;
	for (;k>0; k--) {
		std::cout << n1 + n2 << ' ';
		n1 = n1 + n2;
		n2 = n1 - n2;
	}
}