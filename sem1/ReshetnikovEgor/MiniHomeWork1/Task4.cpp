#include <iostream>

int reverse_numb() {
	int input;
	std::cin >> input;
	int result = 0;
	while (true) {
		result = result * 10 + (input % 10);
		input = input / 10;
		if (input == 0) {
			return result;
		}
	}
}