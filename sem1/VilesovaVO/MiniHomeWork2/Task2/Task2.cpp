#include <iostream>

int main()
{
    int a, b, f;

    std::cout << "Enter the number ";
    std::cin >> b;
    f = 0;

    while (b > 1)
    {
        if (f == b % 2)
        {
            a = b / 2;
            b = a;
        } 
        else
        {
            a = ((b * 3) + 1) / 2;
            b = a;
        }
    }
    std::cout << "Result " << b;
}
