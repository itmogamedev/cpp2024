#include <iostream>

void Fibonacci(int n) {
    int a = 0, b = 1, c;
    for (int i = 0; i < n; i++) {
        std::cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    int n;
    std::cin >> n;
    Fibonacci(n);
    return 0;
}