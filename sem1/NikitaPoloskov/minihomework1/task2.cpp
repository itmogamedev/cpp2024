#include <iostream>

double trapezoid_area(double base_a, double base_b, double height)
{
    return (base_a + base_b) / 2 * height;
}

int main()
{
    double first_base = 5.3, second_base = 12.4, height = 4.1;

    std::cout << trapezoid_area(first_base, second_base, height) << std::endl;

    return 0;
}
