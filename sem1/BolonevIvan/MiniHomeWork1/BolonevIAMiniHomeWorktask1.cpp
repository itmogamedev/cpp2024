#include <iostream>
void square(float b)
{
    std::cout << "Площадь квадрата = "<< b*b << std::endl;
}

int main()
{
    float a;
    setlocale(LC_ALL, "ru");
    std::cout << "Введите длину стороны" << std::endl;
    std::cin >> a;
    square(a);
    return 0;
}
