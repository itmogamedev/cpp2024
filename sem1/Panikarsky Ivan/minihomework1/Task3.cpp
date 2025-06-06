#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int N, Nmax, Cnt, digitsFIB, digitsFIB_bag, digitsFIB_result;
	bool Check;
	digitsFIB = 0;
	digitsFIB_bag = 0;
	digitsFIB_result = 0;
	cout << "\t\t\t\tВведите количество чисел Фибоначчи, которые Вы хотите узнать:";
	cin >> Nmax;
	cout << "\n\n";
	N = Nmax;
	Cnt = 0;
	Check = ((N == Nmax) == 1);

	switch (Check)
	{
	case 1:
		cout << Cnt++ << " Число Фибоначчи: " << digitsFIB << "\n\n";
		N--;
		digitsFIB++;

	case 0:
		for (int i = 1; N != 0; N--)
		{
			digitsFIB_result = digitsFIB + digitsFIB_bag;
			cout << Cnt++ << " Число Фибоначчи: " << digitsFIB_result << "\n\n";
			digitsFIB = digitsFIB_bag;
			digitsFIB_bag = digitsFIB_result;
		}
		break;
	}
}