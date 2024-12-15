#include <iostream>

int square_area = 0;
int side_lenght = 0;
int main() {
	std::cout << "Enter the length of the side of the square: ";
	std::cin >> side_lenght;
	square_area = side_lenght * side_lenght;
	std::cout << square_area;
	return 0;
}