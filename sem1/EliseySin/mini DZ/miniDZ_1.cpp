#include <iostream>
#include <iomanip>

int main() {
    int desetichnoe;

    std::cout << "Введите десятичное число: ";
    std::cin >> desetichnoe;

    std::cout << "Введенное число в шестнадцатиричной системе: " 
              << std::hex << std::uppercase << desetichnoe << std::endl;

    std::cout << "Введенное число в восьмиричной системе: " 
              << std::oct << desetichnoe << std::endl;

}