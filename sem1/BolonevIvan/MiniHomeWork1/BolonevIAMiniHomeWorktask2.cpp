#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru");
	double a, b, c;
	std::cout << "Введите первое основание трапеции" << std::endl;
	std::cin >> a;
	std::cout << "Введите второе основание трапеции" << std::endl;
	std::cin >> b;
	std::cout << "Введите высоту трапеции" << std::endl;
	std::cin >> c;
	std::cout<< (a + b) / 2 * c; 
}
