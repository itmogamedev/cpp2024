#include <iostream>



float area(float side)
{
	return side * side;
}



int main()
{
	float side;
	std::cout << "Enter the length of side of the square: ";
	std::cin >> side;
	std::cout << "Area = " << area(side);
}
