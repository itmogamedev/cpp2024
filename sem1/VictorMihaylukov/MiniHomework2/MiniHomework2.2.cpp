#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");

	cout << "Введите натуральное число:";
	int n = 0;
	cin >> n;
	while (n <= 0) {
		cout << "Число не может быть меньше или равно нулю\n";
		cout << "Введите натуральное число:";
		cin >> n;
	}

	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = (n * 3 + 1) / 2;
		}
	}

	if (n == 1) {
		cout << "Гипотеза подтверждена";
	}
}