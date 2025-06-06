#include <iostream>

float squareOfTrapezium(float p1, float p2, float h)
{
    return (p1+p2)/2*h;
}

int main()
{
    float side1, side2, height;
    std::cin >> side1 >> side2 >> height;
    std::cout<<squareOfTrapezium(side1, side2, height);
}