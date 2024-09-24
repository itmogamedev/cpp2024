#include <iostream>
void trapezoid(float a,float b,float c)
{
    std::cout << "Площадь трапеции = "<< (a +b)* c/2 << std::endl;
}

int main()
{
    float a,b,c;
    setlocale(LC_ALL, "ru");
    std::cout << "Введите длину первого основания" << std::endl;
    std::cin >> a;
    std::cout << "Введите длину второго основания" << std::endl;
    std::cin >> b;
    std::cout << "Введите длину высоты" << std::endl;
    std::cin >> c;
    trapezoid(a, b, c);
    return 0;
}
