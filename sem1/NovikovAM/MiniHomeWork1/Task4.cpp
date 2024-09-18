#include <iostream>

int main() {
	int g;
	std::cout << "Input your number: ";
	std::cin >> g;



	while (g != 0) {
		std::cout << g%10;
		g /= 10; 
	}
}