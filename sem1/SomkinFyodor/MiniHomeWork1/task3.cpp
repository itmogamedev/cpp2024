#include <iostream>


void Fib(int kolichestvo) {
    int first = 0, second = 1;
    std::cout << first << " " << second << " ";
    for (int i = 2; i < kolichestvo; i++) {
        std::cout << first + second << " ";
        std::swap(first, second);
        second += first;
    }
}

int main()
{
    int kolichestvo;
    std::cin >> kolichestvo;
    Fib(kolichestvo);
}

