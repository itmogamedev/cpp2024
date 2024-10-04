#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Russian");
    int a = 0;
    int b;
    int c = 1;
    int n;
    cout << "Введите количество элементов" << endl;
    cin >> n;
    cout << c << " ";
    for (int i = 0; i < n - 1; ++i) {
        b = a + c;
        a = c;
        c = b;
        cout << b << " ";
    }
}

