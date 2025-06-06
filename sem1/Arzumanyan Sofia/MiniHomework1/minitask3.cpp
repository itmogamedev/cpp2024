#include <iostream>

int main() {
	int q = 0; int w = 1; int e = 0; int r; int y = 0;
	std::cin >> r;

	while (y < r) {
		q = w;
		w = e;
		e = q + w;
		std::cout << e << " ";
		y++;
	}

}