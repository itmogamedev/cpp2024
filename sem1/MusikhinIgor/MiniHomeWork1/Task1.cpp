#include <iostream>

int SquareArea(int Length) {
    return Length * Length;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int InputSide;
    std::cout << "¬ведите длину стороны квадрата: ";
    std::cin >> InputSide;

    int Area = SquareArea(InputSide);
    std::cout << "ѕлощадь квадрата: " << Area;

    return 0;
}