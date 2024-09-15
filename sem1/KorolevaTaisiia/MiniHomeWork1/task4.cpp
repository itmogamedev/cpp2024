#include <iostream>

/*Пользователь вводит число.
Преобразовать его в другое число,
цифры которого будут следовать в обратном порядке по сравнению с введенным пользователем числом.
std::string пользоваться нельзя.
*/



int reverse_number(int number) {
    int reversed_number = 0;
    while (number != 0) {
        reversed_number *= 10;
        reversed_number += number % 10;
        number /= 10;
    }
    return reversed_number;
}

int main() {
    std::cout << reverse_number(1234567);
    return 0;
}
