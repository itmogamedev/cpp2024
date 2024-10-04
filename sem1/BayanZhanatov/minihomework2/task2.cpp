#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Russian");
    int a;
    cout << "Проверим гипотезу Сиракуз: введите натуральное число." << endl;
    cin >> a;
    while (a != 1) {
        if (a % 2 == 0) {
            a /= 2;
        }
        else {
            a = (a * 3 + 1) / 2;
        }
        cout << a << endl;
    }
}

