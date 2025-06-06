#include <iostream>
#include <string>

std::string sistem_eight(int ten) {
    std::string number = "";
    do {
        number += std::to_string(ten % 8);
        ten /= 8;
    } while (ten != 0);
    std::reverse(number.begin(), number.end());
    return number;
}

std::string sistem_sixteen(int ten) {
    const std::string database = "0123456789ABCDEF";
    std::string number = "";
    do {
        number += database[(ten % 16)];
        ten /= 16;
    } while (ten != 0);
    std::reverse(number.begin(), number.end());
    return number;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int data;
    int request; 
    std::cout << "Добрый день!\nВведите десятичное число:";
    std::cin >> data;
    std::cout << "Если Вы хотите преобразовать десятичное число в восьмеричное, то введите 1.\n Если Вы хотите преобразовать десятичное число в шетснадцатеричное, то введите 2.\n";
    std::cin >> request;
    if (request == 1) {
        std::cout << sistem_eight(data);
    }
    else if (request == 2) {
        std::cout << sistem_sixteen(data);
    }
}

