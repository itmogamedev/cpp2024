#include <iostream>

double SquareTrapezoid(double baseUp, double baseDown, double sideLeft, double sideRight)
{
    double part = (pow(baseDown - baseUp, 2) + pow(sideLeft, 2) - pow(sideRight, 2)) / (2 * (baseDown - baseUp));
    double square = (baseDown + baseUp) / 2 * (std::sqrt(pow(sideLeft, 2) - pow(part, 2)));

    return square;
}


int main()
{
    double baseUp = 0;
    double baseDown = 0;
    double sideLeft = 0;
    double sideRight = 0;

    while (true)
    {
        std::cout << "Enter up base of trapezoid: ";
        std::cin >> baseUp;
        std::cout << "Enter down base of trapezoid: ";
        std::cin >> baseDown;
        std::cout << "Enter left side of trapezoid: ";
        std::cin >> sideLeft;
        std::cout << "Enter right side of trapezoid: ";
        std::cin >> sideRight;

        if (baseUp < 0 || baseDown < 0 || sideLeft < 0 || sideRight < 0)
        {
            break;
        }
        else
        {
            std::cout << "Square of your trapezoid is " << SquareTrapezoid(baseUp, baseDown, sideLeft, sideRight) << std::endl;
        }
    }
}
