#include <iostream>

void ConversionTo8(int value) {
	std::cout << std::oct << value << std::endl;
}

void ConversionTo16(int value) {
	std::cout << std::hex << value << std::endl;
}

int main() {
	int value = 0;
	std::cout << "Enter a number:" << std::endl;
	std::cin >> value;
	ConversionTo8(value);
	ConversionTo16(value);
	return 0;
}