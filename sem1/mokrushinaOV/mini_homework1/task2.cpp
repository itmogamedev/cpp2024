#include <iostream>


int trapezoid_area(int hight, int smaller_base, int bigger_base) {
    int area = ((smaller_base + bigger_base) / 2) * hight;
    return area;
}


int main()
{
    int hight;
    int smaller_base;
    int bigger_base;

    std::cout << "Enter trapezoid hight: ";
    std::cin >> hight;

    std::cout << "Enter trapezoid's smaller base: ";
    std::cin >> smaller_base;

    std::cout << "Enter trapezoid's bigger base: ";
    std::cin >> bigger_base;

    std::cout << "Trapezoid area: " << trapezoid_area(hight, smaller_base, bigger_base) << std::endl;
}