#include <iostream>

void decimaltohexadecimal(int decimal) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Шестнадцатеричное значение: " << std::hex << std::uppercase << decimal << std::endl;
}

void decimaltooctal(int decimal) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Восьмеричное значение: " << std::oct << decimal << std::endl;
}

int main() {
    int decimal;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите десятичное число: ";
    std::cin >> decimal;

    decimaltohexadecimal(decimal);
    decimaltooctal(decimal);

    return 0;
}