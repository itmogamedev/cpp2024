#include <iostream>

int fun(int a) {
    return a * a;
}

int main()
{
    int a;
    std::cout << "введите длину стороны квадрата" << std::endl;
    std::cin >> a;
    std::cout << "площадь = " << std :: endl<< fun(a);
}