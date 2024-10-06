
#include <iostream>

int main()
{
    int i;
    std::cout << "Enter any natural number. Аccording to the Syracuse hypothesis, the result should be 1 "<< std::endl;
    std::cin >> i;
    while(i!=1)
    {
        if (i % 2 == 0)
        {
            std::cout << i << " / 2 = " << i / 2 << std:: endl;
            i = i / 2;

        }
        else
        {
            std::cout << '(' << i << " * 3 + 1 ) /2 = " << (i * 3 + 1) / 2 << std::endl;
            i = (i * 3 + 1) / 2;
        }
    }
    std::cout << i;
}
