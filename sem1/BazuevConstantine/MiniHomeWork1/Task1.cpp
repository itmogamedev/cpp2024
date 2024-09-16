#include "iostream"

float Area(float lenght);

int main()
{
	float len;
	std::cout << "Enter a lenght of square: ";
	std::cin >> len;
	std::cout << "The area of square will be: " << Area(len);

}

float Area(float lenght)
{
	return lenght * lenght;
}