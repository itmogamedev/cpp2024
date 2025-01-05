//
// Автор - Матюхин Алексей
//

#include "iostream"

char* to_base_n(const int number, const int base) {
    if (base < 2 || base > 16) {
        return nullptr;
    }

    int n = number;
    int length = 0;
    while (n != 0) {
        n /= base;
        length++;
    }

    char* result = new char[length + 1];
    result[length] = '\0';

    n = number;
    for (int i = length - 1; i >= 0; i--) {
        const int digit = n % base;
        result[i] = digit < 10 ? '0' + digit : 'A' + digit - 10;
        n /= base;
    }

    return result;
}

void print_num_in_base(const int number, const int base) {
    char* result = to_base_n(number, base);
    if (result == nullptr) {
        std::cout << "Invalid base" << std::endl;
    }
    else {
        std::cout << "Number in base " << base << ": " << result << std::endl;
        delete[] result;
    }
}

int main() {
    int mode;
    std::cout << "Enter the mode (1 - decimal to custom (2-16), 2 - decimal to octal, 3 - decimal to hexadecimal): ";
    std::cin >> mode;

    switch (mode) {
    case 1: {
        std::cout << "Selected custom base" << std::endl;

        int number, base;
        std::cout << "Enter the number: ";
        std::cin >> number;

        std::cout << "Enter the base: ";
        std::cin >> base;

        print_num_in_base(number, base);
        break;
    }
    case 2: {
        std::cout << "Selected octal base" << std::endl;

        int number;
        std::cout << "Enter the number: ";
        std::cin >> number;

        print_num_in_base(number, 8);
        break;
    }
    case 3: {
        int number;
        std::cout << "Selected hexadecimal base" << std::endl;
        std::cout << "Enter the number: ";
        std::cin >> number;

        print_num_in_base(number, 16);
        break;
    }
    default: {
        std::cout << "Invalid mode" << std::endl;
        break;
    }
    }
}