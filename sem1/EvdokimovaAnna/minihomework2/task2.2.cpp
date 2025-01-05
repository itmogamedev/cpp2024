#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int n;
	cout << "Enter natural number:" << endl;
	cin >> n;
	while (n != 1) 
	{
		if (n % 2 == 0) { n /= 2; }
		else { n = ((n * 3) + 1) / 2; }
		cout << n << endl;
	}
	return 0;
}
