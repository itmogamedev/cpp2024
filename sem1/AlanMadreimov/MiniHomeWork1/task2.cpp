#include<iostream>

using namespace std;

double TrapezoidArea(double h, double a, double b) {
	return h * (a + b) / 2;
}

int main() {
	double h, a, b;

	do {
		cout << "Enter Height of Trapezoid: ";
		cin >> h;
		cout << "Enter base a: ";
		cin >> a;
		cout << "Enter base b: ";
		cin >> b;
		if ((a <= 0) or (b <= 0) or (h <= 0)) {
			cout << "Height and bases can't be - or 0" << endl;
		}
	} while ((a <= 0) or (b <= 0) or (h <= 0));

	cout << TrapezoidArea(h, a, b);

	return 0;
}
