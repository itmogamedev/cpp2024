#include <iostream>

int main()
{
    int Number, Reverse_Number = 0;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите число: ";
    std::cin >> Number;
    while (Number != 0)
    {
        Reverse_Number *= 10;
        Reverse_Number += Number % 10;
        Number /= 10;
    }
    std::cout << Reverse_Number;
}