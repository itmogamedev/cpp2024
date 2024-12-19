#include <iostream>

int main() 
{
    int number;
    int rnumber = 0;

    std::cout << "Введите любое число, чтобы его развернуть: ";
    std::cin >> number;

    while (number != 0)
    {
        rnumber *= 10;
        rnumber += chislo % 10;
        number /= 10;
    }

    std::cout << rnumber;

}
