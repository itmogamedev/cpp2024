#include <iostream>


float TrapezoidArea(float base1, float base2, float height)
{
    return (base1 + base2) / 2 * height;
}

int main()
{
    float base1, base2, height;
    std::cout << "Enter the length of the first base: ";
    std::cin >> base1;
    std::cout << "Enter the length of the second base: ";
    std::cin >> base2;
    std::cout << "Now enter the height: ";
    std::cin >> height;
    std::cout << "The area of the trapezoid is: " << TrapezoidArea(base1, base2, height);
}