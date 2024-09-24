#include <iostream>
using namespace std;
int main()
{
	int a;
	int b;
	int h;
	cout << "Enter the length of the trapezoid bases:";
	cin >> a >> b;
	cout << "Enter the length of the trapezoid height:";
	cin >> h;
	cout << (a + b) / 2 * h;
	return 0;
}