#include <iostream>

double square_area(double x)
{
    return x * x;
}

int main()
{
    double sq_side = 9.5;
    std::cout << square_area(sq_side) << std::endl;

    return 0;
}
