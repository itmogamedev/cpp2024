

#include <iostream>

int Square(int a)
{
    return a * a;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int b;
    std::cout << "Введите длину стороны a: ";
    std::cin >> b;
    std::cout << "Площадь данного квадрата = " << Square(b);
}
