#include <iostream>

/*Task1: Реализовать функцию преобразования из десятичного числа в шестнадцатеричную и восьмеричную систему.*/

#include <string>
#include <algorithm>

std::string toBase(long long decimalNumber, int base) {
    std::string result;
    const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    do {
        result += digits[decimalNumber % base];
        decimalNumber /= base;
    } while (decimalNumber != 0);
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    long long num;
    std::cout << "Enter your number in a decimal numeral system: \n";
    std::cin >> num;
    std::cout << "Std functions (For self check) \n";
    std::cout << "16-based numeral system " << std::hex << num << std::endl;
    std::cout << "8-based numeral system " << std::oct << num << std::endl;
    std::cout << "My function \n";
    std::cout << "16-based numeral system " << toBase(num, 16) << std::endl;
    std::cout << "8-based  numeral system " << std::oct << toBase(num, 8) << std::endl;
    return 0;
}
