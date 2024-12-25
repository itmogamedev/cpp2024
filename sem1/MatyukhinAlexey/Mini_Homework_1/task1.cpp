//
// Автор - Матюхин Алексей
//

#include "iostream"

float squareArea(const float side) {
    return side * side;
}

int main() {
    float side;

    std::cout << "Enter the side of the square: ";
    std::cin >> side;

    const float area = squareArea(side);
    std::cout << "Area of the square: " << area << std::endl;

    return 0;
}