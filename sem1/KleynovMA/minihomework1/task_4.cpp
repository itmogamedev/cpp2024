#include <iostream>

// task 4

int reverse_number(int num) {
    int reversed = 0;

    while (num > 0) {
        int lastDigit = num % 10;
        reversed = reversed * 10 + lastDigit;
        num /= 10;
    }
    return reversed;
}

int main() {
    const std::string text = "Enter the number: ";
    int number;
    
    std::cout << text;
    std::cin >> number;
    
    const bool is_negative = number < 0;
    if (is_negative) {
        number = -number;
    }

    int reversedNumber = reverse_number(number);
    
    if (is_negative) {
        reversedNumber = -reversedNumber;
    }

    const std::string res_text = "Result is: ";
    std::cout << res_text << reversedNumber << '\n';
    return 0;
}
