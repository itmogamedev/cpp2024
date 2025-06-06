#include <iostream>
int S_trapeze(int a, int b, int h) {
    return (a + b) / 2 * h;
}
int AD = 0;
int BC = 0;
int h = 0;
int main()
{
    std::cout << "Введите основания трапеции: ";
    std::cin >> AD;
    std::cin >> BC;
    std::cout << "Введите высоту трапеции: ";
    std::cin >> h;
    std::cout << "Площадь трапеции: " << S_trapeze(AD, BC, h);

}