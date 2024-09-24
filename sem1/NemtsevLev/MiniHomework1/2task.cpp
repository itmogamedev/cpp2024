//2 задача

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, h;

    std::cout << "Нижнее основание" << std::endl;
    std::cin >> a;
    
    std::cout << "Верхнее основание" << std::endl;
    std::cin >> b;
    
    std::cout << "Высота" << std::endl;
    std::cin >> h;
    
    std::cout << (a + b) / 2 * h;
}