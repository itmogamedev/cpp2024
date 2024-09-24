#include <iostream>

int fun() 
{
    int n = 0;

    int x = 0;
    int a = 0;
    int b = 1;
    int c = 0;

    std::cout << "Кол-во чисел Фибоначчи: ";
    std::cin >> n;

    while (x < n) 
    {       
        a = b;
        b = c;
        c = a + b;
        std::cout << c <<", ";
        x++;
    }

    return 0;
}

int main()
{
    fun();
}