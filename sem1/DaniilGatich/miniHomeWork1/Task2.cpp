#include <iostream>

float trapSquare(float side1, float side2, float height)
{
    std::cout << "Enter upper side of your trapeze:";
    std::cin >> side1;
    std::cout << "Enter bottom side of your trapeze:";
    std::cin >> side2;
    std::cout << "Enter height of your trapeze:";
    std::cin >> height;
    std::cout << "Square of your trapeze is - " << (side1 + side2) / 2 * height;
    return 0;
}

int main()
{
    float usersSide1 = 0;
    float usersSide2 = 0;
    float usersHeight = 0;
    trapSquare(usersSide1, usersSide2, usersHeight);
}