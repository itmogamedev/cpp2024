#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Russian");
    int a;
    cout << "¬ведите сторону квадрата" << endl;
    cin >> a;
    cout << a * a;
}

