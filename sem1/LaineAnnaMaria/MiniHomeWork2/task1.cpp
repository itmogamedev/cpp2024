#include <iostream>
#include <string>

std::string Converter(int number, int base) {
    if (number < 0) { return ""; }
    if (base < 2 || base > 16) { return ""; }
    if (number == 0) { return "0"; }

    int new_number_length = ceil(log(number) / log(base)); // длина числа после перевода в заданную систему счисления

    std::string new_number(new_number_length, ' ');

    for (int i = new_number_length; i > 0; --i) {
        int leftover = number % base;
        new_number[i - 1] = char((leftover < 10) ? '0' + leftover : 'A' + leftover - 10);
        number /= base;
    }

    return new_number;
}

int main() {
    int n, base;
    std::cin >> n >> base;

    std::cout << Converter(n, base);
}