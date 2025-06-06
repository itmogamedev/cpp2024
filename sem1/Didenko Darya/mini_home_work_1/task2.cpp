#include <iostream>

float trapezoid_area(float a, float b, float h) {
    return ((a + b) * h) * 0.5;
}

int main()
{
    float a, b, h;
    std::cout << "Enter a lenght of a first base: ";
    std::cin >> a;
    std::cout << "Enter a lenght of a second base: ";
    std::cin >> b;
    std::cout << "Enter a height of a trapezoid: ";
    std::cin >> h;
    std::cout << "The area of the trapezoid is: " << trapezoid_area(a, b, h) << std::endl;
}