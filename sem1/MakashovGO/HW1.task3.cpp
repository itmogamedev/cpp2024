#include <iostream>
using std::cin;
using std::cout;


int main()
{
	int n, a = 0, b = 1;
	cin >> n;
	while (n != 0)
	{
		cout << a << ' ';
		b += a;
		a = b - a;
		n--;
	}
}