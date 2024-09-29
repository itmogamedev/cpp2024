#include <iostream>

double func1(double a)
{
    return a * a;
}

int main()
{
    //Задание 1
    int g;
    std::cout << "1) side = ";
    std::cin >> g;
    std::cout << func1(g) << std::endl;
}