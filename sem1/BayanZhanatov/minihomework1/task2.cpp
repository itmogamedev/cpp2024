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
    cout << "������� ������ ��������� ��������" << endl;
    cin >> a;
    cout << "������� ������ ��������� ��������" << endl;
    cin >> b;
    cout << "������� ������ ��������" << endl;
    cin >> h;
    cout << ((a + b) * h) / 2;
}

