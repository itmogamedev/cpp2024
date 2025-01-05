

#include <iostream>
int square(int a) {
    return a * a;
}
int input = 0;
int main()
{
    std::cout << "Введите сторону квадрата: ";
    std::cin >> input;
    std::cout << "Площадь квадрата:" << square(input);
}

