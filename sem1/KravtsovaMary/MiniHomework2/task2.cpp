#include <iostream>
void sir(int a) {
	if (a < 0) {
		std::cout << "Чисто должно быть больше нуля";
		return;
	}
	while (a > 1) {
		if (a % 2 == 0) {
			a = a / 2;
			std::cout << a << std::endl;
		}
		else {
			a = a * 3;
			a++;
			a = a / 2;
			std::cout << a << std::endl;
		}
	}
}
int main() {
	int n;
	std::cin >> n;
	sir(n);
}