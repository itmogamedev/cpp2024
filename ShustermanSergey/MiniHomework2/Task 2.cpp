#include <iostream>

int Sirokuz(int x) {
	while (x != 1) {
		if (x % 2 == 0) {
			x /= 2;
			std::cout << x << std::endl;
		}
		else {
			x = ((x * 3) + 1) / 2;
			std::cout << x << std::endl;
		}
		
	}
	return x;
}

int main() {
	long long int input_num = 0;
	while (input_num == 0 or input_num < 0) {
		std::cout << "Input any NATURAL nmber and I will turn it into 1 via mathematical magic: ";
		std::cin >> input_num;
		if (!std::cin) { // Защита от дурака
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	Sirokuz(input_num);
	std::cout << "TA-DA!" << std::endl;
	return 0;
}