#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int digit;
	cout << "Введите любое число:";
	cin >> digit;
	cout << "Гипотеза гласит, что независимо от выбора числа рано или поздно мы получим 1" << endl;
	cout << "==========================================" << endl;
	while (digit != 1)
	{
		if (digit % 2 == 0)
		{
			digit /= 2;
		}
		else
		{
			digit *= 3;
			++digit;
			digit /= 2;

		}
	}
	cout << "Гипотеза верна, мы получили:\t" << digit;
	return 0;
}