#include <iostream>

int main() {
	int q = 0;
	int w = 0;
	std::cin >> q;
	while (q > 0) {
		w = w * 10;
		w += q % 10;
		q = q / 10;

	}
	std::cout << w;
}