#include <iostream>
int funcTRAPECIA(int a, int b, int c) {
	std::cout << "Ploshad trapecii = " << ((a + b) * 1 / 2) * c;
	return a;
}
int main() {
	int Osnovane1, Osnavane2, Visota;
	std::cout << "Vvedite 1 i 2 osnovanie trapecii" << std::endl;
	std::cin >> Osnavane2 >> Osnovane1;
	std::cout << "Vvedte visotu trapecii" << std::endl;
	std::cin >> Visota;
	funcTRAPECIA(Osnovane1, Osnavane2, Visota);
	return 0;
}