# include <iostream>

int main() {
	int n;
	std::cin >> n;
	int res = 0;
	while (n) {
		res = res * 10 + n % 10;
		n /= 10;
	}
	std::cout << res;
	return 0;
}