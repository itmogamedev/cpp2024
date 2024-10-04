#include <iostream>

int main()
{
    int n = 0;
    int a = 0;
    int g = 0;
    int b = 1;
    std::cout << "N:";
    std::cin >> n;
    std::cout << b;
    n = n - 1;
    while (n > 0)
    {
        std::cout << a + b;
        g = b;
        b = a + b;
        a = g;
        n = n-1;
    }

}