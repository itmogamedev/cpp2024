#include <iostream>

// task 1

double square_area(const double side)
{
    return side*side;
}

int main()
{
    const int side = 5;
    const double result = square_area(side);

    std::cout << "The area of a square is equal to " << result << '\n';
    return 0;
}
