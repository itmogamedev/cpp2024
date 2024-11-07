#include <iostream>

int main() {
    for (long i = 1; i < 1000000001; i++) {
        long num = i;
        while (num > 1) {
            if (num % 2 == 0) {
                num /= 2;
            }
            else {
                num = (num * 3) + 1;
            }
        }
    }
    std::cout << "Syracuse's hypothesis is true for natural numbers up to 1,000,000,000";
}