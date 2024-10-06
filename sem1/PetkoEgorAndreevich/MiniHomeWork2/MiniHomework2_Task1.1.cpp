#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::oct;
using std::hex;
using std::dec;


int main()
{
	setlocale(LC_ALL, "Russian");
	int chislo;
	cout << "Введите число в 10-ричной системе исчесления" << endl;
	cin >> chislo;
	cout << "8-ричное и 16-ричное представление" << endl;
	cout << oct << chislo << dec << hex  << " " << chislo;
}