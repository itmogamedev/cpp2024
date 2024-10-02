#include <iostream>

float trapezoid(float firstBase, float secondBase, float height)
{
    return ((firstBase + secondBase) / 2) * height;
}

int main()
{
    float firstBase, secondBase, height;
    std::cout << "Enter the first bases length of your trapezoid: ";
    std::cin >> firstBase;

    std::cout << "Enter the second bases length of your trapezoid: ";
    std::cin >> secondBase;

    std::cout << "Enter the height length of your trapezoid: ";
    std::cin >> height;

    std::cout << "Area of your trapezoid: " << trapezoid(firstBase, secondBase, height) << std::endl;
}