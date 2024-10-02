#include <iostream>

int main() {
    int chislo;
    int obchislo = 0;

    std::cout << "Введите любое число, чтобы его развернуть: ";
    std::cin >> chislo;

    while (chislo != 0)
    {
        obchislo *= 10;
        obchislo += chislo % 10;
        chislo /= 10;
    }

    std::cout << obchislo;

}