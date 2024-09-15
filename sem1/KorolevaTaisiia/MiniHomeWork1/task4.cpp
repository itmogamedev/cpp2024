#include <iostream>

/*Пользователь вводит число.
Преобразовать его в другое число,
цифры которого будут следовать в обратном порядке по сравнению с введенным пользователем числом.
std::string пользоваться нельзя.
*/



int reverse_number(int number) { // Ведущие нули в новой версии числа не возвращаются
    int reversed_number = 0;
    while (number != 0) {
        reversed_number *= 10;
        reversed_number += number % 10;
        number /= 10;
    }
    return reversed_number;
}

int count_digits(int number) {
    int digits = 0;
    while (number != 0) {
        number /= 10;
        digits++;
    }
    return digits;
}

void show_smart_reverse_number(int number) { // Вывод с ведущими нулями
    int rev_num = reverse_number(number);
    int how_many_zeroes = count_digits(number) - count_digits(rev_num);
    for (int i = 0; i < how_many_zeroes; ++i) {
        std::cout << 0;
    }
    std::cout<< rev_num << '\n';
}

int main() {
    std::cout << reverse_number(1234567) << '\n'; // если следовать ТЗ
    show_smart_reverse_number(1000000);
    return 0;
}
