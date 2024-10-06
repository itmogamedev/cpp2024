#include <iostream>

int main() {
    long long num;
    std::cin >> num;
    if (num < 0) {
        std::cout << "The number must be natural" << std::endl;
    }

    while (num != 1 and num > 0) {
        if (num % 2 == 0) {
            num /= 2;
            std::cout << num << std::endl;

        }
        else {
            num = (3 * num + 1) / 2;
            std::cout << num << std::endl;
        }
    }
}