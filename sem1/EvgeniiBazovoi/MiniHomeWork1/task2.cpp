#include <iostream>

int sq(float a, int h) {
	return a / 2 * h;
}

int main() {
	int a;
	int h;
	std::cout << "write the summ of lengths " << std::endl;
	std::cin >> a;
	std::cout << "write the value of height" << std::endl;
	std::cin >> h;
	std::cout << "the value of the trapezoid area:" << sq(a, h);
	return 0;
}