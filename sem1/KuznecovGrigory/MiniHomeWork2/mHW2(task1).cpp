#include <iostream>
int OctConversion(int number)
{
	std::cout << std::oct << number;
	return 0;
}
int HexConversion(int number)
{
	std::cout << std::hex << number;
	return 0;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int Number = 0, Choose = 0;
	std::cout << "Выберите в какую систему счисления нужно перевести ваше число:" << '\n';
	std::cout << "1. 8 система счисления:" << '\n' << "2. 16 система счисления:" << '\n' << "3. Выйти из программы:" << '\n';
	std::cin >> Choose;
	switch(Choose)
	{
	case 1:
		std::cout << "Введите ваше число в 10 системе счисления:" << '\n';
		std::cin >> Number;
		OctConversion(Number);
		break;
	case 2:
		std::cout << "Введите ваше число в 10 системе счисления:" << '\n';
		std::cin >> Number;
		HexConversion(Number);
		break;
	case 3:
		break;
	default:
		std::cout << "Можно ввести только цифры 1, 2 и 3";
	}
}