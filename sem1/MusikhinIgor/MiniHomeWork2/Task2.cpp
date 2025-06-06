#include <iostream>

int main() {
    int number;

    do {
        std::cout << "Enter a natural number: ";
        std::cin >> number;

        if (number <= 0) {
            std::cout << "Wrong" << std::endl;
        }
    } while (number <= 0);

    while (number != 1) {
        std::cout << number << " ";

        if (number % 2 == 0) {
            number = number / 2;
        }
        else {
            number = (3 * number + 1) / 2;
        }
    }

    std::cout << number << std::endl;

    return 0;
}