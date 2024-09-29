#include <iostream>

int main()
{
    int F1 = 1;
    int F2 = 1;
    int n = 1
        std::cout << "Введите номер числа Фибоначчи";
    std::cin >> n;
    std::cout << 1;
    while (n > 1) 
    {
        std::cout << F2;
        int F = F1 + F2;
        F1 = F2;
        F2 = F;
        n = n - 1;
    }
    return 0;
}