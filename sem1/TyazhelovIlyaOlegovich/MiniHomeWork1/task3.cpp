#include <iostream>

void fibonacci(int usersInput) {
    int first {1};
    int second {0};
    for (int i {1}; i <= usersInput; i++) {
        if (i % 2 != 0) {
            first += second;
            std::cout << first << ' ';
        }
        else {
            second += first;
            std::cout << second << ' ';
        }
    }
}

int main() {
    std::cout << "Введите, сколько чисел Фибоначчи вы бы хотели увидеть: ";
    int usersNumber {};
    std::cin >> usersNumber;

    std::cout << "Ваш ряд: "; 
    fibonacci(usersNumber);

    return 0;
}