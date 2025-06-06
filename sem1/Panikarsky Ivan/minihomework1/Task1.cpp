#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int SizeSquar, SquareArea;
	cout << "Введите длину стороны квадрата:";
	cin >> SizeSquar;
	SquareArea = SizeSquar * SizeSquar;
	cout << "Площадь Вашего квадрата:" << SquareArea;
}