#include <iostream>
int findTrapezoidSpace(int trapezoidHeight, int trapezoidMidline);
int main()
{
    int trapezoidHeight = 0;
    int trapezoidMidline = 0;
    std::cout << "Введите размер высоты трапеции" << std::endl;
    std::cin >> trapezoidHeight;
    std::cout << "Введите размер средней линии трапеции" << std::endl;
    std::cin >> trapezoidMidline;
    std::cout << "Площадь трапеции равна " << findTrapezoidSpace(trapezoidHeight, trapezoidMidline);
}
int findTrapezoidSpace(int trapezoidHeight, int trapezoidMidline){
    return trapezoidHeight*trapezoidMidline;
}