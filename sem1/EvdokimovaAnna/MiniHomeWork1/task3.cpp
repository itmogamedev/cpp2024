#include <iostream>
using std::cout;
using std::cin;

int main()
{
	int a = 0; 
	int b = 1; 
	int c; 
	int x;
	cin >> x;
	cout << 1 << "";
	for (int i = 0; i < x - 1; ++i) 
	{
		c = a + b;
		a = b;
		b = c;
		cout << c;
	}
	return 0;
}
