#include <iostream>

void numberReverse(long long int number) {
    while (number > 0) {
        std::cout << number % 10;
        number = number / 10;
    }
}

int main() {
    long long int number;
    std::cout << "Please, enter the number you want to reverse:" << std::endl;
    std::cin >> number;
    std::cout << "Reversed number:" << std::endl;
    numberReverse(number);
}