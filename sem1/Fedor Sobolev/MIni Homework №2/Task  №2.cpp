#include <iostream>

int main() {

    int number;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите натуральное число: ";
    std::cin >> number;

    while (number != 1) {
        if (number % 2 == 0) {
            number /= 2;
        }
        else {
            number = (number * 3 + 1) / 2;
        }

        std::cout << number << " ";
    }

    std::cout << std::endl << "Число стало равно 1." << std::endl;

    return 0;
}