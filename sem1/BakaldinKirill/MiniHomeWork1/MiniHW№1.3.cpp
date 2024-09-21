#include <iostream>

int main() {
	std::cout << "Enter number of elements" << std::endl;
	int N = 0;
	std::cin >> N;
	int a = 0;
	int b = 1;
	int c = 0;
	std::cout << "Fibonacci numbers: " << 0 << " " << 1 << " ";
	for (int count_elements = 2; count_elements < N; ++count_elements) {
		c = a + b;
		a = b;
		b = c;
		std::cout <<  c << " ";
	}
}