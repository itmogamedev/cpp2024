#include <iostream>

int main()
{
    int Height = 0;
    int LowerBase = 0;
    int UpperBase = 0;
    std::cout << "������� ������ ��������";
    std::cin >> Height;
    std::cout << "������� ������ ��������� ��������� ��������";
    std::cin >> LowerBase;
    std::cout << "������� ������ ��������� ��������� ��������";
    std::cin >> UpperBase;
    int AreaOfTrapezoid = (LowerBase + UpperBase) / 2 * Height;
    std::cout << AreaOfTrapezoid;
    return 0;
}