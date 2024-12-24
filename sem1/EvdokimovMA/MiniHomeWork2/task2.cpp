//
// Created by Максим Евдокимов on 29.09.2024.
//

#include "iostream"

bool check_syracuse_sequence(const int n) {
    int number = n;

    while (number > 1) {
        number = number % 2 == 0 ? number / 2 : (number * 3 + 1) / 2;
    }

    if (number == 1) {
        std::cout << "The Syracuse sequence for " << n << " converges to 1" << std::endl;
    } else {
        std::cout << "The Syracuse sequence for " << n << " does not converge to 1" << std::endl;
    }

    return number == 1;
}

int main() {
    std::cout << "This program tests the Siracusa hypothesis by traversing all numbers in a given interval." << std::endl;
    std::cout << "The hypothesis states that all numbers eventually converge to 1." << std::endl;
    std::cout << "Enter the interval to test. It must be a subset of the natural numbers." << std::endl;

    int start_number, end_number;
    std::cout << "Enter the start number: ";
    std::cin >> start_number;

    std::cout << "Enter the end number: ";
    std::cin >> end_number;

    if (start_number > end_number) {
        std::cout << "The start number must be less than or equal to the end number" << std::endl;
        return 1;
    }

    bool is_converging = true;
    for (int i = start_number; i <= end_number && is_converging; i++) {
        is_converging = check_syracuse_sequence(i);
    }

    if (is_converging) {
        std::cout << "All numbers in the interval converge to 1" << std::endl;
    } else {
        std::cout << "Not all numbers in the interval converge to 1" << std::endl;
    }
}