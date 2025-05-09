#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int a,b;
	cout << "¬ведите систему счислени€:";
	cin >> b;
	cout << "¬ведите число:";
	cin >> a;
	if (b == 16) {
		cout << hex << a << endl;
	}
	else if (b == 8) {
		cout << oct << a << endl;
	}
	else {
		cout << "ќшибка!";
	}
	return 0;
}