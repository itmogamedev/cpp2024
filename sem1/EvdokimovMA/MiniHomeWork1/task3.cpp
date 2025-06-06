//
// Created by Максим Евдокимов on 16.09.2024.
//

#include "iostream"

void compute_n_fibonacci(const int n) {
    long long int* fibonacci = new long long int[std::max(n, 0)];

    if(n >= 1) {
        fibonacci[0] = 0;
        std::cout << fibonacci[0] << std::endl;
    }
    if(n >= 2) {
        fibonacci[1] = 1;
        std::cout << fibonacci[1] << std::endl;
    }

    for(int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        std::cout << fibonacci[i] << std::endl;
    }

    delete[] fibonacci;
}

int main() {
    int n;

    std::cout << "Enter the number of terms in the fibonacci sequence: ";
    std::cin >> n;

    compute_n_fibonacci(n);

    return 0;
}