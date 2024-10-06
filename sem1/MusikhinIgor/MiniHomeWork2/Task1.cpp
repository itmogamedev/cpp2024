#include <iostream>
#include <string>

std::string DecimalToHex(int num) {
    std::string hexDigits = "0123456789ABCDEF";
    std::string hexResult = "";

    if (num == 0) {
        return "0";
    }

    while (num > 0) {
        int remainder = num % 16;
        hexResult = hexDigits[remainder] + hexResult;
        num /= 16;
    }

    return hexResult;
}

std::string DecimalToOct(int num) {
    std::string octResult = "";

    if (num == 0) {
        return "0";
    }

    while (num > 0) {
        int remainder = num % 8;
        octResult = std::to_string(remainder) + octResult;
        num /= 8;
    }

    return octResult;
}

int main() {
    int decimalNumber;

    std::cout << "Enter a decimal number: ";
    std::cin >> decimalNumber;

    std::cout << "Hexadecimal number system: " << DecimalToHex(decimalNumber) << std::endl;
    std::cout << "Octal number system: " << DecimalToOct(decimalNumber) << std::endl;

    return 0;
}