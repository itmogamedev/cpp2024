#include <iostream>

using std::cout;
using std::cin;

int a;

int main()
{
	cout << "Enter a number: ";
	cin >> a;
	cout << "\nhex:";
	cout << hex << a;

	cout << "\noct:";
	cout << oct  << a;

	return 0;
}
