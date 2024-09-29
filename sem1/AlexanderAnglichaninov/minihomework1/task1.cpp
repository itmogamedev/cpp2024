#include <iostream>

double SArea(double a) {
    double result = a * a;
    return result;
}

int main() {
    double a;
    std::cin >> a;
    std::cout << SArea(a);
    return 0;
}