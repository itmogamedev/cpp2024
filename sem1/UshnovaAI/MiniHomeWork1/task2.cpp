#include <iostream>

int areaTrapezoid(int base1, int base2, int height) {
	return (base1+base2)*height/2;
}

int main() {
	int base1 = 4;
	int base2 = 2;
	int height = 2;
	std::cout << "The area of ​​the strapezium is " << areaTrapezoid(base1, base2, height) << std::endl;
}