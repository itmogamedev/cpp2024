#include <iostream>

float trapezoidArea(float firstFoundation, float secondFoundation, float height) {
    return (firstFoundation + secondFoundation) * height / 2;
}

float trapezoidAreaSecond(float middleLine, float height) {
    return middleLine * height;
}

int main() {
    std::cout << "Проверка, площадь трапеции в виде десятичной дроби " << trapezoidArea(2, 2.6, 4) << '\n';
    std::cout << "Проверка, площадь трапеции в виде целого числа " << trapezoidArea(2, 2.5, 4) << '\n';

    std::cout << "Площадь трапеции через среднюю линию " << trapezoidAreaSecond(2.5, 4) << '\n';

    return 0;
}