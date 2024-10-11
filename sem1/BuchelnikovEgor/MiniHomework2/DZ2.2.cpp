#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    int Natural;
    std::cout << "Введите любое натуральное число " << std::endl;
    std::cin >> Natural;
    if (Natural <= 0) {
        return 0; 
    }
    while (Natural != 1) {
        if (Natural % 2 == 0) {
            std::cout << "Число четное, поэтому делим на 2 - ";
            Natural = Natural / 2;
            std::cout << Natural << std::endl;
        }
        else {
            std::cout << "Число нечетное, поэтому умножаем на 3, добавляем 1 и делим на 2 - ";
            Natural = Natural * 3 + 1;
            std::cout << Natural << std::endl;
            Natural = Natural / 2; 
            std::cout << Natural << std::endl;
        }
    }
    return 0;
}
