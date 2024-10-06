#include <iostream>

void hypothesis(long long int number) {
    while (number != 1) {
        if (number % 2 == 0) {
            std::cout << number << "/2=" << number / 2 << std::endl;
            number /= 2;
        }
        else {
            std::cout << "(3*" << number << "+1)/2=" << (3 * number + 1) / 2 << std::endl;
            number = (3 * number + 1) / 2;
        }
    }
}

int main() {
    std::cout << "Please, enter the natural number you want to check the Syracuse hypothesis for:" << std::endl;
    long long int number;
    std::cin >> number;
    while (number <= 0) {
        std::cout << "Nope. A natural number, please: " << std::endl;
        std::cin >> number;
    }
    hypothesis(number);
    std::cout << "The Syracuse hypothesis for this number is correct!";
}