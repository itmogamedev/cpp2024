#include <iostream>

int revers(int re_number) {
	if (re_number == 0) {
		return 0;
	}
	std::cout << (re_number % 10);
	return revers(re_number / 10);
}

int main() {
	int N;
	std::cin >> N;
	revers(N);
}