#include <iostream>
int funcTRAPECIA(int a, int b, int c) {
	std::cout << "Ploshad trapecii = " << ((a + b) * 1 / 2) * c;
	return a;
}
int main() {
	int base1, base2, height;
	std::cout << "Vvedite 1 i 2 osnovanie trapecii" << std::endl;
	std::cin >> base2 >> base1;
	std::cout << "Vvedte visotu trapecii" << std::endl;
	std::cin >> height;
	funcTRAPECIA(base1, base2, height);
	return 0;
}
