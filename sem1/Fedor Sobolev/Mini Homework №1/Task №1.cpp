#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int sideofthesquare;
    std::cout << "Введите длину стороны квадрата:";
    std::cin >> sideofthesquare;
    std::cout << sideofthesquare * sideofthesquare;
}
