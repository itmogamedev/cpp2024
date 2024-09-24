//1 задача

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int a;
    
    std::cout << "Сторона квадрата" << std::endl;
    std::cin >> a;
    std::cout << a * a;
}
