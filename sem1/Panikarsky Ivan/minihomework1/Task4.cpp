#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int number, digit, number_bag, cnt, number_bag1;
	cout << "Введите Ваше число:";
	cin >> number;
	cout << "\n";
	cnt = 0;
	number_bag = number;
	for (; number > 0; )
	{
		number /= 10;
		cnt++;
	}
	cout << "Ваше число в обратном порядке:";
	for (; cnt > 0; cnt--)
	{
		switch (number_bag % 10)
		{
		case 0:
			cout << "0";
			number_bag /= 10;
			break;
		case 1:
			cout << "1";
			number_bag /= 10;
			break;
		case 2:
			cout << "2";
			number_bag /= 10;
			break;
		case 3:
			cout << "3";
			number_bag /= 10;
			break;
		case 4:
			cout << "4";
			number_bag /= 10;
			break;
		case 5:
			cout << "5";
			number_bag /= 10;
			break;
		case 6:
			cout << "6";
			number_bag /= 10;
			break;
		case 7:
			cout << "7";
			number_bag /= 10;
			break;
		case 8:
			cout << "8";
			number_bag /= 10;
			break;
		case 9:
			cout << "9";
			number_bag /= 10;
			break;
		}
	}
	cout << "\n";
}