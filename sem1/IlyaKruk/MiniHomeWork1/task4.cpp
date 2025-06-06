#include <iostream>
using namespace std;
int main()
{
	long long int a;
	cout << "Which number do you want to reverse?" << endl;
	cin >> a;
	while (true)
	{
		cout << a % 10;
		a /= 10;
		if (a == 0)
		{
			break;
		}
	}
}