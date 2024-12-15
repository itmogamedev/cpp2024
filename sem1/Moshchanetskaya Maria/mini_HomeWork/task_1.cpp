#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    float side_a;
    std::cout << "введите сторону квадрата " << std:: endl;
    std::cin >> side_a;
    std::cout << "площадь квадрата = " << side_a * side_a;
}