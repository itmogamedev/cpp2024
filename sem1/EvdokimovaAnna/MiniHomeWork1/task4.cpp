#include <iostream>

using std::cout;
using std::cin;


int main()
{
	int a, b = 0;
	cout << "Enter a number: ";
	cin >> a;
	while (a > 0) 
	{
		b *= 10;
		b += (a % 10);
		a /=10;
	}
	cout << b;
	return 0;
}
