#include <iostream>
#include <string>
#include <algorithm>

int main() {
	int a;
	std::string b = "";
	std::cin >> a;
	int a0 = a;
	while (a > 0) {
		std::string a1 = std::to_string(a % 8);
		b += a1;
		a /= 8;
	}
	reverse(b.begin(), b.end());
	std::cout << b << " - oct" << std::endl;

	std::string b0 = "";
	while (a0 > 0) {
		std::string a01 = std::to_string(a0 % 16);
		b0 += a01;
		a0 /= 16;
	}
	reverse(b0.begin(), b0.end());
	std::cout << b0 << " - hex";
}