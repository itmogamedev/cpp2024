#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Russian");
    int a = 0; int b = 1; int c; int x; 
    cout << "Введите кол-во элементов" << endl;
    cin >> x;
    cout << 1 << " ";
    for (int i = 0; i < x - 1; ++i) {
        c = a + b;
        a = b;
        b = c;
        cout << c << " ";
    }
}
