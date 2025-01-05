#include <iostream>

int func(int a) {
	std::cout << "S kvadrata = " << a*a;
	return a;
}
int main() {
	int b;
	std::cout << "Vvedite storonu kradrata" << std::endl;
	std::cin >> b;
	func(b);
	return 0;
}

