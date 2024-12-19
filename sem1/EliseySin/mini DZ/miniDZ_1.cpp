#include <iostream>
#include <iomanip>

int main() {
    int decimal;

    std::cout << "Введите десятичное число: ";
    std::cin >> decimal;

    std::cout << "Введенное число в шестнадцатиричной системе: " 
              << std::hex << std::uppercase << decimal << std::endl;

    std::cout << "Введенное число в восьмиричной системе: " 
              << std::oct << decimal << std::endl;

}
