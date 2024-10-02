#include <iostream>

int reverse(int input);

int main() {
    int input;
    std::cout << "Введите число:";
    std::cin >> input;
    std::cout << reverse(input);
}

int reverse(int input) {
    int reversed = 0;
    while (input != 0) {
        reversed = reversed * 10 + input % 10;
        input /= 10;
    }
    return reversed;
}