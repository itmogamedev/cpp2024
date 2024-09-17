#include <iostream>
using namespace std;

int main()
{ 
	int n, reversed = 0;
	cout << "Enter the number: ";
	cin >> n;
	while (n != 0) {
		int remain = n % 10;
		if (remain == 0) cout << 0;
		reversed = reversed * 10 + remain;
		n /= 10;
	}
	cout << reversed;
}







