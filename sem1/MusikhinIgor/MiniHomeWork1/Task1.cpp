#include <iostream>

int SquareArea(int Length) {
    return Length * Length;
}

int main() {
    int InputSide;
    std::cout << "Enter the side length of the square: ";
    std::cin >> InputSide;

    int Area = SquareArea(InputSide);
    std::cout << "Square area: " << Area;

    return 0;
}