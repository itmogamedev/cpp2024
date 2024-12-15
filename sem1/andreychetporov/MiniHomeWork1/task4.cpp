#include <iostream>


int main() {
	unsigned long long int n;
	short int num;
	std::cin >> n;
	while (n != 0) {
		num = n % 10;
		n = n / 10;
		std::cout << num;
	}
}