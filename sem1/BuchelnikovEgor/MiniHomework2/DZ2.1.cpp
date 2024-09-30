#include <iostream>
#include <string>

int Sistema8(int a) {
    int Число = 0, Разряд = 1;

    std::cout << "Число " << a << " в восьмеричной системе счисления = ";

    while (a != 0) {
        int Остаток = a % 8;  
        Число += Остаток * Разряд;  
        a /= 8;  
        Разряд *= 10;  
    }
    std::cout << Число << std::endl;
    return Число;
}
std::string Sistema16(int a) {
    if (a == 0) {
        std::cout << "Число 0 в шестнадцатеричной системе счисления = 0" << std::endl;
        return "0";
    }

    std::string Число16;
    std::cout << "Число " << a << " в шестнадцатеричной системе счисления = ";

    while (a != 0) {
        int Остаток = a % 16;
        if (Остаток < 10) {
            Число16 = char('0' + Остаток) + Число16;
        }
        else {
            Число16 = char('A' + Остаток - 10) + Число16;
        }
        a /= 16; 
    }

    std::cout << Число16 << std::endl; 
    return Число16;
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
