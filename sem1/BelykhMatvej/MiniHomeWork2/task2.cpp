#include <iostream>

void Sirakus(long long n) {
    if (n > 0) {
        while (n != 1) {
            if (n % 2 == 0) {
                std::cout << n << "/2=" << n / 2 << std::endl;
                n = n / 2;
            }
            else {
                std::cout << "(" << n << "*3+1)/2=" << (n * 3 + 1) / 2 << std::endl;
                n = (n * 3 + 1) / 2;
            }
        }
    }
    else {
        std::cout << "The number must be natural" << std::endl;
    }
}

int main() {
    long long n;
    std::cin >> n;
    Sirakus(n);
}