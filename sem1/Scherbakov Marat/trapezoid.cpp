#include <iostream>

int main() {
    int side_1, side_2, height;

setlocale(LC_ALL, "Russian");
    std::cout << "Длина первого основания: ";
    std::cin >> side_1;
    std::cout << "Длина второго основания: ";
    std::cin >> side_2;
    std::cout << "Высота: ";
    std::cin >> height;

    int Trapezoid_Area = ((side_1 + side_2) / 2) * height;

    std::cout << Trapezoid_Area;
    return 0;
}
