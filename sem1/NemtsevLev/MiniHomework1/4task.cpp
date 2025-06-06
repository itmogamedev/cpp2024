//4 задача

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b = 0;
    std::cout << "Введите число" << std::endl;
    std::cin >> a;
    
    while (a > 0) 
    {
        b *= 10;
        b += a % 10;
        a /= 10;
    }
    
    std::cout << b;
}
