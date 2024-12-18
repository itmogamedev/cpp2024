#include <iostream>

int calcTrapezeArea(int base1, int base2, int height) {
	return (base1 + base2) * height / 2;
}

int main() {
	int base1 = 3;
	int base2 = 5;
	int height = 4;
	std::cout << "Area of trapeze = " << calcTrapezeArea(side);
	return 0;
}