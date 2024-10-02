#include <iostream>
int square(int a, int b, int h);
int main() {
    int a, b, h;
    std::cout << "Enter a numbers:";
    std::cin >> a;
    std::cin >> b;
    std::cin >> h;
    std::cout << square(a, b, h);
}

int square(int a, int b, int h) {
    return ((a+b)*h)/2;
}