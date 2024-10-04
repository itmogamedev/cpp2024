#include <iostream>

int areaSquare(int value) {
	return value * value;
}

int main() {
	int side = 4;
	std::cout << "Area of ​​a square with side " << side << " is equal to " << areaSquare(side) << std::endl;
}