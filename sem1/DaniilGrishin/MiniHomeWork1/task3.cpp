#include <iostream>

using std::cout;
using std::cin;

int main() {
	int N;
	unsigned long long int nextn;  //nextn - следующее число
	unsigned long long int prev1 = 1; //prev1 - предыдущее число
	unsigned long long int prev2 = 0; //prev2 - предыдущее на 2 левее позиции от текущего
	cout << "Enter the length of Fibonacci row: ";
	cin >> N;
	if (N >= 94) {
		cout << "The data type does not allow counting a row greater than 93 "; //т.к. максимальное значение unsigned long long int - 2^64, что меньше 94-го числа Фибоначчи
		return 0;
	}
	for (int i = 1; i <= N; ++i) {
			nextn = prev1 + prev2; 
			prev1 = prev2;
			prev2 = nextn;
			cout << nextn << " ";
	}
}