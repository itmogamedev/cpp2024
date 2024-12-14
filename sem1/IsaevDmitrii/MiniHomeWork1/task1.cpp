#include <iostream>

float squareOfSquare(float a)
{
    return a * a;
}

int main()
{
    float side;
    std::cin >> side;
    std::cout<<squareOfSquare(side);
}