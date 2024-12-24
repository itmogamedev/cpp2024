#include <iostream>

long long function_reverse_number(long long given_number) {
    long long final_number = 0;
    bool is_negative = false;

    if (given_number < 0) {
        is_negative = true;
        given_number = -given_number;
    }

    while (given_number > 0) {
        final_number *= 10;
        final_number = final_number + given_number % 10;
        given_number /= 10;
    }
    if (is_negative == true) {
        final_number = -final_number;
    }
    return final_number;
}


int main() {
    long long n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Reversed number is: " << function_reverse_number(n) << std::endl;

}