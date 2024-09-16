#include <iostream>

int main()
{
    int reverse = 0; // Итоговое число
    int lastnum = 0; // это для цикла
    int input = 0; // Вводимое число
    std::cout << "Enter: ";
    std::cin >> input;
    while (input!= 0) {
        lastnum = input % 10; // Берёт последнее число
        reverse = reverse * 10 + lastnum;
        input /= 10; // Убирает последнее число из вводимого числа
    }
    std::cout << reverse;
}