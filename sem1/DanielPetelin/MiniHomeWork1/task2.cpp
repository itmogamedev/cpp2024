#include <iostream>

int fun(int a, int b, int h) {
	return (a + b) * h / 2;
}

int main() {
	int a = 4;
	int b = 2;
	int h = 2;
	std::cout << "Площадь трапеции = " << fun(a, b, h) << std::endl;
}