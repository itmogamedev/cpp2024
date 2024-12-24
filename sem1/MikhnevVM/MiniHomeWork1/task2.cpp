#include <iostream>

double area_of_a_trapezoid(double a, double b, double h)
{
    return (a+b)/2*h;
}

int main()
{
    double base_a, base_b, heigh_of_trapezoid;
    std::cout << "Введите длинну меньшего основания трапеции:" << "\n";
    std::cin >> base_a;
    std::cout << "Введите длинну большего основания трапеции:" << "\n";
    std::cin >> base_b;
    std::cout << "Введите длинну высоу трапеции:" << "\n";
    std::cin >> heigh_of_trapezoid;

    std::cout << "Площадь трапеции = " << area_of_a_trapezoid(base_a, base_b, heigh_of_trapezoid);
}