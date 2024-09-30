#include <iostream>
using namespace std;

static void Siracus(int num) {
	int temp = num;
	cout << temp;
	while (temp != 1) {
		if (temp % 2 == 0) temp /= 2;
		else temp = (temp * 3 + 1) / 2;
		cout << " -> " << temp;
	}
}

int main()
{ 
	int num;
	cout << "Enter your number: ";
	cin >> num;
	Siracus(num);
}







