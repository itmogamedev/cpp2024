#include <iostream>

int main() {
	unsigned int value = 0;
	std::cout << "Enter a natural number:" << std::endl;
	std::cin >> value;
	while (value != 1) {
		if ((value % 2) == 0) {
			value = value / 2;

		}
		else {
			value = (value * 3 + 1) / 2;
		}
	}
	std::cout << "Value=" << value << " True!" << std::endl;
}
