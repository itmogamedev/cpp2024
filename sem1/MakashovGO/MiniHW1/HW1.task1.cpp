#include <iostream>


float AreaOfRectangle(float side1, float side2)
{
    return side1 * side2;
}

int main()
{
    float side1, side2;
    std::cout << "Enter the length of the first side: ";
    std::cin >> side1;
    std::cout << "Enter the length of the second side: ";
    std::cin >> side2;
    std::cout << "The area of the rectangle is: " << AreaOfRectangle(side1, side2);
}