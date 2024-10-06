#include <iostream>
double AreaOfTrapezium(double LargerBase, double SmallerBase, double Height) {
	return (LargerBase + SmallerBase) * Height / 2;
}

int main() {
	double a = 0, b = 0, h = 0;
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;
	
	if (a > b) {
		std::cout << "h = ";
	}
	else
		std::cout << "Invalid input";

	std::cin >> h;
	double S = AreaOfTrapezium(a, b, h);
	std::cout << "S = ";
	std::cout << S;
	return 0;
}