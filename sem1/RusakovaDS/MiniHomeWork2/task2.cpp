#include <iostream>
int main() {
    long long number;
    std::cout << "Enter natural number" << std::endl;
    std::cin >> number;

    while (true) {
        if (number % 2 == 0) {
            number /= 2;
        }
        else {
            number = (3 * number + 1) / 2;
        }
        std::cout << number << " ";
        if (number == 1) {
            std::cout << "Hipotesys confirmed" << std::endl;
            break;
        }
    }
}