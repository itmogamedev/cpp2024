#include <iostream>

using std::cin;
using std::cout;

int main() {
	int num, res;
	res = 0;
	cout << "Enter a number to reverse: ";
	cin >> num;
	while (num > 0) {
		res *= 10;
		res += num % 10;
		num /= 10;
	}
	cout << "Reversed: " << res;
}