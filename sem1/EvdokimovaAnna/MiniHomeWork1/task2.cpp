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
	cout << "������� 1"<<endl;
	cin >> a;
	cout << "������� 2"<<endl;
	cin >> b;
	cout << "������"<<endl;
	cin >> h;
	cout << "������� �������� " << endl;
	cout << (a + b) / 2 * h;
}
