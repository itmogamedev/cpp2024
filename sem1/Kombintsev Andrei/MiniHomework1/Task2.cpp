
#include <iostream>

int main()
{
    std::cout << "Enter side of trapezoid";
    float a = 0;
    float b = 0;
    std::cin >> a;
    std::cin >> b;
    std::cout << "Enter trapezoid height";
    float h = 0;
    std::cin >> h;
    std::cout << "Area of trapezoid" << (a + b) / 2.0 * h;
}

