#include <iostream>
#include <cmath>

int main()
{
	setlocale(LC_ALL, "Russian");

	int side;
	std::cout << "Введ: " ;
	std::cin >> side;
	std::cout << "Площадь квадрата: " << pow(side, 2) << std::endl;

}