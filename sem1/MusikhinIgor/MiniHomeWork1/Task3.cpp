#include <iostream>

int main() {
    int N;
    std::cout << "Enter the number of elements of the Fibonacci series: ";
    std::cin >> N;
    int a = 0;
    int b = 1;
    int buffer;

    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            std::cout << a << " ";
            continue;
        }
        if (i == 1) {
            std::cout << b << " ";
            continue;
        }
        buffer = a + b;
        a = b;
        b = buffer;
        std::cout << buffer << " ";
    }

    return 0;
}