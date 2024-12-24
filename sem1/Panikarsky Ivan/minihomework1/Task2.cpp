#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	float UpperSideTrapezoid, LowerSideTrapezoid, TrapezoidHeight, HalfSumBases, TrapezoidArea;
	cout << "Введите длину верхнего основания Вашей трапеции:";
	cin >> UpperSideTrapezoid;
	cout << "Введите длину нижнего основания Вашей трапеции:";
	cin >> LowerSideTrapezoid;
	cout << "Введите высоту Вашей трапеции:";
	cin >> TrapezoidHeight;
	HalfSumBases = (UpperSideTrapezoid + LowerSideTrapezoid) / 2;
	TrapezoidArea = HalfSumBases * TrapezoidHeight;
	cout << "Площадь Вашей трапеции:" << TrapezoidArea;
}