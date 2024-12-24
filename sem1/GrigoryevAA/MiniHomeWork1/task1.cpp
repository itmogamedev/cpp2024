#include <iostream>

double SquareBox(double side)
{
    return side * side;
}


int main()
{
    double side = 0;

    while (true)
    {
        std::cout << "Enter side of your box: ";
        std::cin >> side;
        if (side < 0)
        {
            break;
        }
        else
        {
            std::cout << "Square of your box is " << SquareBox(side) << std::endl;
        }
    }
}
