#include <iostream>

void hypothesisOfSyrakuz(int usersNumber) {
    int amountOfIterations {1};
    while (usersNumber != 1) {
        if (usersNumber % 2 == 0)
            usersNumber /= 2;
        else
            usersNumber = 3 * usersNumber + 1;
        std::cout << amountOfIterations << " iteration gave: " << usersNumber << '\n';
        amountOfIterations++;
    }
    std::cout << "Hypothesis is right!";
}

int main() {
    std::cout << "Please enter your integer (every symbol past comma will be discarded): ";
    float usersNumber {};
    std::cin >> usersNumber;

    hypothesisOfSyrakuz(usersNumber);

    return 0;
}