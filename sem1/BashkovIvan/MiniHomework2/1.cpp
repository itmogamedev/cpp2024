#include <iostream>
#include <string>

const std::string alphabet = "0123456789ABCDEF";

void transition(int number, int base) {
    std::string result, sign;
    if (number < 0) {
        sign = "-";
        number *= -1;
    }
    if (number != 0) {
        while (number > 0) {
            result = alphabet[number % base] + result;
            number /= base;
        }
    }
    else {
        result = "0";
    }
    std::cout << "Your number in " << base << "-based numeral system: " << sign << result << std::endl;
}

int main() {
    int number, base;
    std::cout << "Hello there." << std::endl;
    std::cout << "Please, insert an integer:" << std::endl;
    std::cin >> number;
    std::cout << "Please, insert the base of the numeral system you want to transit the number into (8 or 16):" << std::endl;
    std::cin >> base;
    while (base != 8 && base != 16) {
        std::cout << "I guess you have misread the sentence above. It's 8-based or 16-based numeral system only. So please, enter 8 or 16:" << std::endl;
        std::cin >> base;
    }
    transition(number, base);
    std::cout << "Thank you for using this program. Have a nice day!" << std::endl;
}