#include <iostream>

int square(int si) {
	return si * si;
}

int main(){
	std::cout << "Enter squares side";
	int side = 0;
	std::cin >> side;
	std::cout << "Area of ​​the square:";
	std::cout << square(side);
	return 0;
}