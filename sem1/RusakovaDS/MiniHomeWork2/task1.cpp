#include <iostream>
#include <string>

const std::string digits = "0123456789ABCDEF";

void convert(int number, int base) {
    std::string result, sign;
    if (number < 0) {
        sign = "-";
        number *= -1;
    }
    if (number == 0) {
        result = "0";
    }
    while (number > 0) {
        result = digits[number % base] + result;
        number /= base;
    }

    std::cout << "Number in " << base << " base: " << sign << result << std::endl;
}

void convertOct(int number) {
    convert(number, 8);
}

void convertHex(int number) {
    convert(number, 16);
}
int main() {
    int number = 0;
    std::cout << "Enter your number:" << std::endl;
    std::cin >> number;

    convertOct(number);
    convertHex(number);
}