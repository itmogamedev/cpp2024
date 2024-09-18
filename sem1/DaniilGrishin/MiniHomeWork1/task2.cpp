#include <iostream>

using std::cin;
using std::cout;

int main() {
	double a, b, h;
	cout << "Enter the first base of a trapezoid: ";
	cin >> a;
	cout << "Enter the second base of a trapezoid: ";
	cin >> b;
	cout << "Enter the height of a trapezoid: ";
	cin >> h;
	cout << "Area of a trapezoid: " << (a + b) / 2 * h;
}