#include <iostream>

double func2(double base1, double base2, double height)
{
    return (base1 + base2) / 2 * height;

}

int main()
{
    //Задание 2
    int b1 = 1, b2 = 2, h = 3;
    std::cout << "2) base 1 >> ";
    std::cin >> b1;
    std::cout << "   base 1 >> ";
    std::cin >> b2;
    std::cout << "   height >> ";
    std::cin >> h;
    std::cout << func2(b1, b2, h) << std::endl;
}