//
// Автор - Матюхин Алексей
//

#include "iostream"

float trapezoidzArea(const float base0, const float base1, const float height) {
    return (base0 + base1) * 0.5f * height;
}

int main() {
    float base0, base1, height;

    std::cout << "Enter the bases of the trapezoid: ";
    std::cin >> base0 >> base1;

    std::cout << "Enter the height of the trapezoid: ";
    std::cin >> height;

    const float area = trapezoidzArea(base0, base1, height);
    std::cout << "Area of the trapezoid: " << area << std::endl;

    return 0;
}