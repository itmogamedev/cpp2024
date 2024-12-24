#include <iostream>
#include <string>
void trans(int a) {
	if (a == 0) {
		std::cout << "0";
	}
	int a10 = a;
	int a16, a8;
	std::string s8;
	std::string s16;
	if (a > 0) {
		while (a10 > 0) {
			s8 = std::to_string(a10 % 8) + s8;
			a10 = a10 / 8;
		}
		a8 = std::stoi(s8);
		std::cout << a8 << std::endl;
		a10 = a;
		while (a10 > 0) {
			s16 = std::to_string(a10 % 16) + s16;
			a10 = a10 / 16;
		}
		a16 = std::stoi(s16);
		std::cout << a16;
	}
	if (a < 0) {
		a10 = a * -1;
		while (a10 > 0) {
			s8 = std::to_string(a10 % 8) + s8;
			a10 = a10 / 8;
		}
		a8 = std::stoi(s8);
		std::cout << a8 * -1 << std::endl;
		a10 = a * -1;
		while (a10 > 0) {
			s16 = std::to_string(a10 % 16) + s16;
			a10 = a10 / 16;
		}
		a16 = std::stoi(s16);
		std::cout << a16 * -1;
	}
}
int main() {
	int n;
	std::cin >> n;
	trans(n);
}