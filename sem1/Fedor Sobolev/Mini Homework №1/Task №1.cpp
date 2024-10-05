
#include <iostream>
using std::cout;
using std::cin;

int main()
{
    setlocale(LC_ALL, "Russian");
    int sideofthesquare;
    cout << "Введите длину стороны квадрата:";
    cin >> sideofthesquare;
    cout << sideofthesquare * sideofthesquare;
}