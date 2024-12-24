#include <iostream>

void numbersRepresentation(int usersNumber, int usersBase) {
    usersBase == 8 ? std::cout << "Your number in in octal representation is: " << std::oct << usersNumber :
                     std::cout << "Your number in hexadecimal representation is: " << std::hex << usersNumber;
}

int main() {
    std::cout << "Please enter your integer (every symbol past comma will be discarded): ";
    float usersNumber {};
    std::cin >> usersNumber;

    std::cout << "Please enter the base of new number (8 or 16): ";
    int usersBase {};
    std::cin >> usersBase;

    while (usersBase != 8 and usersBase != 16) {
        std::cout << "Please enter 8 or 16: ";
        std::cin >> usersBase;
    }

    numbersRepresentation(usersNumber, usersBase);

    return 0;
}