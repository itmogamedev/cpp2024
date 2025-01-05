

#include <iostream>



int area(int side) {
	return side * side;
}



int main()
{
	int side = 0;
	std::cout << "Enter a side of square: ";
	std::cin >> side;
	std::cout << "area of square: " << area(side);
}

