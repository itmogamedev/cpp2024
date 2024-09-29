#include <iostream>

int main()
{
    int Height = 0;
    int LowerBase = 0;
    int UpperBase = 0;
    std::cout << "¬ведите высоту трапеции";
    std::cin >> Height;
    std::cout << "¬ведите первое основание основание трапеции";
    std::cin >> LowerBase;
    std::cout << "¬ведите второе основание основание трапеции";
    std::cin >> UpperBase;
    int AreaOfTrapezoid = (LowerBase + UpperBase) / 2 * Height;
    std::cout << AreaOfTrapezoid;
    return 0;
}