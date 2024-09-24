#include <iostream>

int base1, base2, height;

int count_trapezium_area(int b1, int b2, int h)
{
    return 0.5 * (b1 + b2) * h;
}

int main()
{
    std::cout << "Trapezium area calculation" << std::endl;
    std::cout << "Enter first trapezium base: ";
    std::cin >> base1;
    std::cout << "Enter second trapezium base: ";
    std::cin >> base2;
    std::cout << "Enter trapezium height: ";
    std::cin >> height;
    std::cout << "Area of trapezium: " << count_trapezium_area(base1, base2, height);

    return 0;
}
