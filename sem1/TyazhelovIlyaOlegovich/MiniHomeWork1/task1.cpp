#include <iostream>
//float type just in case
float squareArea(float side) {
    return side * side;
}

int main() {
    std::cout << "Проверка, площадь квадрата в виде десятичной дроби " << squareArea(2.5) << '\n';
    std::cout << "Проверка, площадь квадрата в виде целого числа " << squareArea(25) << '\n';

    return 0;
}