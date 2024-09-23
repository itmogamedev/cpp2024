#include <iostream>

void trapezoid_area(int side_base1, int side_base2, int side_hight) {
	std::cout << (side_hight * (side_base1 + side_base2) / 2) << "\n";
	return;
}


int main() {
	trapezoid_area(2, 4, 4);
}

