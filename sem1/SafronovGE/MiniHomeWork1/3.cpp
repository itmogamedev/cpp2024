#include <iostream>

unsigned long long int Fibonacci_series(int N, unsigned long long int Fn1, unsigned long long int Fn2) {
	if (N == 0) {
		std::cout << '\n';
		return 0;
	}
	std::cout << Fn1 << ' ';
	return Fibonacci_series(N - 1, Fn2, Fn1 + Fn2);
}

int main() {
	int N;
	std::cin >> N;
	Fibonacci_series(N, 0, 1);
}

