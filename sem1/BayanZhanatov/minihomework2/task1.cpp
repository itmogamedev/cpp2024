#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main() {
    setlocale(LC_ALL, "Russian");
    int a;

    cout << "�������� ����� � ���������� ������� ���������� � ��������� �������� ��� � ������������ � ����������������� ������� ����������." << endl;
    cin >> a;

    cout << "����� � ������������ ������� ����������: ";
    cout << std::oct << a << endl;

    cout << "����� � ����������������� ������� ����������: ";
    cout << std::hex << a << endl;
}