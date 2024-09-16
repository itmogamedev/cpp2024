#include "iostream"

float Area(float lenght_1, float lenght_2, float height);

int main()
{
	float len_1, len_2, height;
	std::cout << "Enter a lenghts of trapezoid (first a, then b): ";
	std::cin >> len_1 >> len_2;
	std::cout << "Enter a height of trapezoid: ";
	std::cin >> height;
	std::cout << "The area of trapezoid will be: " << Area(len_1, len_2, height);

}

float Area(float lenght_1, float lenght_2, float height)
{
	return (lenght_1 + lenght_2) * (height / 2);
}