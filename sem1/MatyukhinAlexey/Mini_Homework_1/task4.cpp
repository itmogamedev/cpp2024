//
// Автор - Матюхин Алексей
//

#include "iostream"

int revert_number(int number) {
    int revert_number = 0;

    while (number != 0) {
        revert_number = revert_number * 10 + number % 10;
        number /= 10;
    }

    return revert_number;
}

int main() {
    int n;

    std::cout << "Enter a number: ";
    std::cin >> n;

    const int reverted_n = revert_number(n);
    std::cout << "Reverted number: " << reverted_n << std::endl;

    return 0;
}