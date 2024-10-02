#include <iostream>
int main()
{
	setlocale(LC_ALL, "Russian");
	int Number, ReversedNumber = 0;
	std::cout << "Введите число:";
	std::cin >> Number;
	while (Number > 0)
	{
		ReversedNumber = ReversedNumber * 10 + Number % 10;
		Number = Number / 10;
	}
	std::cout << "Ваше число перевернуто:" << ReversedNumber;
	return 0;
}