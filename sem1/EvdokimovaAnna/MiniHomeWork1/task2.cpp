#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int a;
	int b;
	int h;
	cout << "Enter the side of the larger base: ";
	cin >> a;
	cout << "\nEnter the smaller base side: ";
	cin >> b;
	cout << "\nEnter the height: ";
	cin >> h;
	cout << "\nArea of the trapezoid: ";
	cout << (a + b) / 2 * h;
	return 0;
}
