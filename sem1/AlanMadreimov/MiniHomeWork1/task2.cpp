#include<iostream>



double TrapezoidArea(double h, double a, double b) {
	return h * (a + b) / 2;
}

int main() {
	double h, a, b;

	do {
		std::cout << "Enter Height of Trapezoid: ";
		std::cin >> h;
		std::cout << "Enter base a: ";
		std::cin >> a;
		std::cout << "Enter base b: ";
		std::cin >> b;
		if ((a <= 0) or (b <= 0) or (h <= 0)) {
			std::cout << "Height and bases can't be - or 0" << std::endl;
		}
	} while ((a <= 0) or (b <= 0) or (h <= 0));

	std::cout << TrapezoidArea(h, a, b);

	return 0;
}
