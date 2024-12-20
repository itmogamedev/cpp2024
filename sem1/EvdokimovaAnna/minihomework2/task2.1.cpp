#include <iostream>

using std::cout;
using std::cin;

int a;
int main()
{
	cout<< "Enter a number: ";
	cin >> a;
	cout << "\nNumber in 16-character system: ";
	cout << hex << a;
	
	cout << "\nNumber in 8-character system: ";
	cout << oct  << a;

	return 0;
}
