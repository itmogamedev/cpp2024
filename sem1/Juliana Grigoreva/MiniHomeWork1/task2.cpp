#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int(a);
    int(b);
    int(h);
    std::cout << "Определение площади трапеции" << std::endl;
    std::cout << "Введите вверхнюю сторону трапеции" << std::endl;
    std::cin >> a;
    std::cout << "Введите нижнюю сторону трапеции" << std::endl;
    std::cin >> b;
    std::cout << "Введите высоту трапеции" << std::endl;
    std::cin >> h;
    std::cout << "S = " << (a + b) / 2 * h;
}

