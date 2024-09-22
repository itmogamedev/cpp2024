#include <iostream>

int main() {
	int number;
	int i0 = 0;
	int i1 = 1;
	std::cin >> number;
	std::cout << "1 ";
	for (int i = 0; i < number; i++) {
		std::cout << (i1 + i0) << " ";
		i1 = i0 + i1;
		i0 = i1 - i0;
	}
}
