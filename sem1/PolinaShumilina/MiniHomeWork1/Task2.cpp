#include <iostream>

int main()
{
    int a;
    std::cout << "Enter the upper base of the trapezoid - ";
    std::cin >> a;
    int b;
    std::cout << "Enter the lower base of the trapezoid - ";
    std::cin >> b;
    int h;
    std::cout << "Enter the hight of the trapezoid - ";
    std::cin >> h;
    std::cout << (a + b) / 2 * h;
}
