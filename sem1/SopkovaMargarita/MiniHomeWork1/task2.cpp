#include <iostream>

int trapecia(int a, int b, int h) {
	return (a + b) * h / 2;
}

int main() {
	int side_a = 0;
	int side_b = 0;
	int high = 0;
	std::cout << "Enter Trapezoid sides and high";
	std::cin >> side_a;
	std::cin >> side_b;
	std::cin >> high;
	std::cout << "Area of the trapezoid:";
	std::cout << trapecia(side_a, side_b, high);
	return 0;
}
