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
    cout << "¬ведите первое основание трапеции" << endl;
    cin >> a;
    cout << "¬ведите второе основание трапеции" << endl;
    cin >> b;
    cout << "¬ведите высоту трапеции" << endl;
    cin >> h;
    cout << ((a + b) * h) / 2;
}

