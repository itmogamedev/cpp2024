
#include <iostream>

int main()  // ЗАДАНИЕ 2
{
    setlocale(LC_ALL, "Russian");
    float base_a;
    float base_b;
    float height_c;
    std::cout << "введите первое основание трапеции" << std::endl;
    std::cin >> base_a;
    std::cout << "введите второе основание трапеции" << std::endl;
    std::cin >> base_b;
    std::cout << "введите высоту трапеции " << std::endl;
    std::cin >> height_c;
    std::cout << " площадь трапеции = " << (base_a + base_b) / 2 * height_c;
}