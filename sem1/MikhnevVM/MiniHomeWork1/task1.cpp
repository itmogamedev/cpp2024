#include <iostream>

int area_of_a_square(int a)
{
    return a*a;
}

int main()
{
    int side_of_the_square;
    std::cout << "Введите длинну стороны квадрата:" << "\n";
    std::cin >> side_of_the_square;

    std::cout << "Площадь квадрата = " << area_of_a_square(side_of_the_square);
}