#include <iostream>

int main() {
	int number;
	int i0 = 0;
	int i1 = 1;
	std::cin >> number;
	if (number == 0) {
		std::cout << "wrong";
	}
	else{
		std::cout << "1 ";
		for (int i = 0; i < number - 1; i++) {
			std::cout << (i1 + i0) << " ";
			i1 = i0 + i1;
			i0 = i1 - i0;
		}
	}
}
