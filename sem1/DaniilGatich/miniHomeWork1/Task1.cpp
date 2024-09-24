#include <iostream>

float square(float side)
{
    std::cout << "Enter side of your quadrant:";
    std::cin >> side;
    std::cout << "Square of your quadrant is - " << side * side;
    return 0;
}

int main()
{
    float usersSide = 0;
    square(usersSide);
}


