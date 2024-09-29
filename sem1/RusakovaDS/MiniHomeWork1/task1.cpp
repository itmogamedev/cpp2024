#include <iostream>

int calcSquareArea(int side) {
	return side * side;
}

int main() {
	int side = 3;
	std::cout << "Area of square w/ side 3 = " << calcSquareArea(side);
	return 0;
}