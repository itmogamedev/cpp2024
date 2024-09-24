//3 задача

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int a = 0; int b = 1; int c; int x;
    
    std::cout << "Сколько чисел Фибоначчи вывести" << std::endl;
    std::cin >> x;
    
    std::cout << 1 << " ";
    
    for (int i = 0; i < x - 1; i++) 
    {
        c = a + b;
        a = b;
        b = c;
        std::cout << c << " ";
    }
}