#include <iostream>
#include <iomanip>

int main() {
    int Number_in_10;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите десятичное число: ";
    std::cin >> Number_in_10;
    
    std::cout << "Это число в шеснадцатеричной системе счисления: " 
              << std::hex << Number_in_10 << std::endl;
              
    std::cout << "Это число в восьмеричной системе счисления: " 
              << std::oct << Number_in_10 << std::endl;
    return 0;
}