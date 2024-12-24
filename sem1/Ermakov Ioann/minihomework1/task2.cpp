

#include <iostream>

int Square(int a, int b, int h)
{
    return (a + b) / 2 * h;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int a1, b1, h1;
    std::cout << "Введите ширину: " << std::endl;
    std::cin >> a1;
    std::cout << "Введите длину: " << std::endl;
    std::cin >> b1;
    std::cout << "Введите высоту: " << std::endl;
    std::cin >> h1;
    std::cout << "Площадь данной трапеции = " << Square(a1, b1, h1);
}
