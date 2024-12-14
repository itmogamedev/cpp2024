#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "How many fibonacci numbers do you want?" << endl;
	cin >> n;
	int a = 0, b = 1, c = 0;
	for (int i = 0; i < n; i++)
	{
		cout << a << ' ';
		c = a;
		a = b;
		b = c + b;
	}
}
