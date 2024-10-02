#include <iostream>

int main() {
	int num1 = 0;
	int num2 = 1;
	int next_num = 0;
	int n;
	std::cout << "Enter number of elements: ";
	std::cin >> n;
	std::cout << "Fibonacci numbers:" << std::endl;
	if (n >= 1)
		std::cout << num1 << std::endl;
	if (n >= 2)
		std::cout << num2;
	for (int i = 0; i < n - 2; i++) {
		next_num = num1 + num2;
		std::cout << next_num << std::endl;
		num1 = num2;
		num2 = next_num;
	}
	return 0;
}
