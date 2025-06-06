#include <iostream>

double TArea(double a, double b, double h) {
    double result = ((a + b) / 2.0) * h;
    return result;
}

int main() {
    double a, b, h;
    std::cout << "Введите длину основания а, длину основания b, и высоту трапеции h через пробел:" << std::endl;
    std::cin >> a >> b >> h;
    std::cout << TArea(a, b, h);
    return 0;
}