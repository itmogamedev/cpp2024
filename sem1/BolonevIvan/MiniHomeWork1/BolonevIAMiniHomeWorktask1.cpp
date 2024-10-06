#include <iostream>
int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Введите сторону квадрата:"<<std::endl;
	int a;
	std::cin >> a;
	std::cout << a * a;
}
