#include <iostream>

int main()
{
    int num;
    int x = 1;
    int n;
    int y = 0;
    std::cout << "Enter number of Fibonacсi numbers";
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        if (i == 0) 
        {
            std::cout << " " << x;
        }
        else
        {
            std::cout << " " << x + y;
            n = x;
            x = x + y;
            y = n;
        }
        

    }
}
