#include <iostream>
#include <string>

int Sistema8(int a) {
    int number = 0, digit = 1;

    std::cout << "Число " << a << " в восьмеричной системе счисления = ";

    while (a != 0) {
        int residue = a % 8;  
        number += residue * digit;  
        a /= 8;  
        digit *= 10;  
    }
    std::cout << number << std::endl;
    return number;
}
std::string Sistema16(int a) {
    if (a == 0) {
        std::cout << "Число 0 в шестнадцатеричной системе счисления = 0" << std::endl;
        return "0";
    }

    std::string number16;
    std::cout << "Число " << a << " в шестнадцатеричной системе счисления = ";

    while (a != 0) {
        int residue = a % 16;
        if (residue < 10) {
            number16 = char('0' + residue) + number16;
        }
        else {
            number16 = char('A' + residue - 10) + number16;
        }
        a /= 16; 
    }

    std::cout << number16 << std::endl; 
    return number16;
}


    int main() {
    setlocale(LC_ALL, "Russian");
    int a;
    std::cout << "Выберите 1 для перевода в 8-ую сс и 2 для 16-ой сс и 3 для выхода :";
    std::cin >> a;
    while (a != 3) {
        switch (a) {
        case 1:
            std::cout << "Введите десятичное число: ";
            std::cin >> a;
            Sistema8(a);
            break;
        case 2:
            std::cout << "Введите десятичное число: ";
            std::cin >> a;
            Sistema16(a);
            break;
        default:
            break;
        }
    }
    return 0;
}
