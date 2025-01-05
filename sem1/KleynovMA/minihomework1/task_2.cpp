#include <iostream>

// task 2

double trapezoid_area(const double side_1, const double side_2, const double height)
{
    double result = (side_1 + side_2) / 2 * height;
    return result;
}

int main()
{
    const int side_1 = 4;
    const int side_2 = 6;
    const int height = 5;
    const double result = trapezoid_area(side_1, side_2, height);

    std::cout << "The area of a trapezoid is equal to " << result << '\n';
    return 0;
}


