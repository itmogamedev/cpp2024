#include <iostream>


void syracuse(int num) {
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = num * 3 + 1;
        }
        std::cout << num << " ";
    }
}


int main() {
    int num;

    std::cout << "Введите натуральное число: ";
    std::cin >> num;

    if (num <= 0) {
        std::cout << "Ошибка: ты не знаешь, что такое натуральное число? Серьёзно?... (Просто введи число больше 0...)." << std::endl;
    } else {
        syracuse(num);
    }

    return 0;
}
