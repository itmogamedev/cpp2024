#include <iostream>
#include <string>
void octal(int a)
{
	std::string number = "";
	std::string help;
	while (a > 0)
	{
		number = std::to_string(a % 8) + number;
		a = a / 8;
	}
	std::cout << "Ваше число в 8-ой системе: ";
	std::cout << number;
}
int main()
{
	setlocale(LC_ALL, "ru");
	int a;
	std::cout << "Введите число для перевода его в 8-у систему"<<std::endl;
	std::cin >> a;
	octal(a);
}