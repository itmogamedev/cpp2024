#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    int Number = 0;
    int ReversedNumber = 0;
    std::cout << "¬ведите число: ";
    std::cin >> Number;

    while (Number != 0) {
        int Digit = Number % 10;
        ReversedNumber = ReversedNumber * 10 + Digit;
        Number = Number / 10;
    }

    std::cout << "ѕеревЄртыш: " << ReversedNumber << std::endl;

    return 0;
}