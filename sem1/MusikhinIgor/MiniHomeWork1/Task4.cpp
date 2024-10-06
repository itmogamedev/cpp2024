#include <iostream>

int main() {
    int Number = 0;
    int ReversedNumber = 0;
    std::cout << "Enter number: ";
    std::cin >> Number;

    while (Number != 0) {
        int Digit = Number % 10;
        ReversedNumber = ReversedNumber * 10 + Digit;
        Number = Number / 10;
    }

    std::cout << "Reversed: " << ReversedNumber << std::endl;

    return 0;
}