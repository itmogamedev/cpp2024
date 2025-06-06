#include <iostream>

long long ReverseNum(long long n) {

    long long digit = n % 10;
    long long nTwo = n % 10; // второе число для раздярдностей

    if (n < 0) {
        std::cout << "Error: The input number cannot be negative" << std::endl;
        return(0);
    }

    else {
        n = n / 10;
        while (n > 0) {
            digit = n % 10;
            n = n / 10;
            nTwo = nTwo * 10;
            nTwo = nTwo + digit;
        }
        return(nTwo);
    }
}

int main() {
    int a;
    std::cin >> a;
    std::cout << ReverseNum(a) << std::endl;
}
