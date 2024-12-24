#include <iostream>

int reverseNumber() {
	int num, res;
	res = 0;
	std::cout << "Enter a number to reverse:" << std::endl;
	std::cin >> num;
	while (num > 0) {
		res *= 10;
		res += num % 10;
		num /= 10;
	}
	std::cout << "Reversed:" << std::endl << res;
	return 0;
}

int main() {
	reverseNumber();
}