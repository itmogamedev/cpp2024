#include <iostream>
using namespace std;

int main()
{ 
	int n, prev1 = 0, prev2 = 1, next;
	cout << "Enter the number: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (i == 0) {
			cout << 0 << "\n";
			continue;
		}
		if (i == 1) {
			cout << 1 << "\n";
			continue;
		}
		next = prev1 + prev2;
		prev1 = prev2;
		prev2 = next;
		cout << next << "\n";
	}
}







