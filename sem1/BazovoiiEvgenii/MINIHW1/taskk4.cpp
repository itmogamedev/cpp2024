#include <iostream>

int reverse(int n) {
    int reverse = 0;
    while (n > 0) {
        reverse = reverse * 10 + n % 10;
        n = n / 10;
    }
    return reverse;
}

int main()
{
    int n;
    std::cout << "write number\n";
    std::cin >> n;
    std::cout << "reverse number is:" << reverse(n);
}