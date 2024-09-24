#include <iostream>

float SquareArea (float side) {
    return side * side;
}

int main() {
    float side;
    std::cout << "Please, enter the side of the square:" << std::endl;
    std::cin >> side;
    std::cout << "The area of the square: " << SquareArea(side);
}