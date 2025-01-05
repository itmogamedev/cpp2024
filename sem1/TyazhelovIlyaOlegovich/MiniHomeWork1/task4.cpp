#include <iostream>

void reverseNumber(long long usersNumber) {
    int temp {};
    while (usersNumber) {
        temp = usersNumber % 10;
        std::cout << temp;
        usersNumber /= 10;
    }
}

int main() {
    std::cout << "Введите ваше число: ";
    long long usersInput {}; //long long type for cases with really big numbers
    std::cin >> usersInput;

    std::cout << "Ваше число в обратно порядке: ";
    reverseNumber(usersInput);

    return 0;
}