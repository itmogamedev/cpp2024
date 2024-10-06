#include <iostream>

int fib(int n) {
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++)
    {
        int ñ = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fib(n);
    return 0;
}