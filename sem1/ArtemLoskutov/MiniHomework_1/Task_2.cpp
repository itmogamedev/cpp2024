#include <iostream>



float area(float base_1, float base_2, float height)
{
	return (base_1 + base_2) * 0.5 * height;
}



int main() 
{
	float base_1, base_2, height;
	std::cout << "Enter the length of the first base of the trapezoid: ";
	std::cin >> base_1;
	std::cout << "Enter the length of the second base of the trapezoid: ";
	std::cin >> base_2;
	std::cout << "Enter the height of a trapezoid: ";
	std::cin >> height;
	std::cout << "Area = " << area(base_1, base_2, height);
}
