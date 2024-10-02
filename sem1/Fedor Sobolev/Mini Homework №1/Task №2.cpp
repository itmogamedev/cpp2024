#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int firstbaseofatrapezoid, secondbaseofatrapezoid, heightoftrapezoid;
    std::cout << "Введите длину первого основании трапеции:";
    std::cin >> firstbaseofatrapezoid;
    std::cout << "Введите длину второго основании трапеции:";
    std::cin >> secondbaseofatrapezoid;
    std::cout << "Введите длину высоты трапеции:";
    std::cin >> heightoftrapezoid;
    std::cout << (firstbaseofatrapezoid * secondbaseofatrapezoid) / 2 * heightoftrapezoid;
}
