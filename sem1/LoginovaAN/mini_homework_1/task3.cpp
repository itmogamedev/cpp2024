# include <iostream>

int main() {
	int n;
	int num1 = 0;
	int num2 = 1;
	int num3;
	std::cin >> n;
	if (n == 1) {
		std::cout << num1 << " ";
	}
	if (n == 2) {
		std::cout << num1 << " ";
		std::cout << num2 << " ";
	}
	else {
		std::cout << num1 << " ";
		std::cout << num2 << " ";
		for (int i = 0; i < n - 2; i++) {
			num3 = num1 + num2;
			std::cout << num3 << " ";
			num1 = num2;
			num2 = num3;
		}
	}
	return 0;
}