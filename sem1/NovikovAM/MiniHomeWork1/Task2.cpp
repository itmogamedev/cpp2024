#include <iostream>

int trapeze(int a, int b, int h);

int main() {
	int a, b, h;
	std::cout << "Input up side: \n";
	std::cin >> a;
	std::cout << "Input down side: \n";
	std::cin >> b;	
	std::cout << "Input height: \n";
	std::cin >> h;
	std::cout << trapeze(a, b, h);
	return 0;
}

int trapeze(int a, int b, int h) {
	return ((a + b) / 2) * h;
}