#include <iostream>

int mirroredNum(int input) {
	int output = 0;
	while (input > 0) {
		output *= 10;
		output+=(input % 10);
		input /= 10;
	}
	return output;
}

int main() {
	std::cout << "Enter number ";
	int input;
	std::cin >> input;
	std::cout << "Mirrored number: "<<mirroredNum(input);
}