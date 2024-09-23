#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	int b;
	int h;
	cout << "Сторона 1"<<endl;
	cin >> a;
	cout << "Сторона 2"<<endl;
	cin >> b;
	cout << "Высота"<<endl;
	cin >> h;
	cout << "Площадь трапеции " << endl;
	cout << (a + b) / 2 * h;
}
