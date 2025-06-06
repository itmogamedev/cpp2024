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
    bool min = false; // Если бы стринги были разрешены, можно было бы сделать проще.
    if (rev_num < 0) {
        min = true;
        rev_num = -rev_num;
    }
    std::cout << rev_num;
    if (min) {
        std::cout << "-";
    }
    std::cout << "\n";
}

int main() {
    int num;
    std::cout << "Number that you want reversed \n";
    std::cin >> num;

    std::cout << "Version without leading zeroes and '-' afterwards: " << reverse_number(num) << '\n'; // если следовать ТЗ
    std::cout << "Alternative version: ";
    show_smart_reverse_number(num);
    return 0;
}
