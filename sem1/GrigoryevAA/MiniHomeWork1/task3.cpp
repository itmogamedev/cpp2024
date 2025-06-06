#include <iostream>

int main()
{
    int N = 0;
    while (true)
    {
        std::cout << "Quantity of Fibonacci numbers: ";
        std::cin >> N;
        std::cout << "" << std::endl;
        if (N == 0)
        {
            break;
        }
        else if (N == 1)
        {
            std::cout << 0 << std::endl;
        }
        else if (N == 2)
        {
            std::cout << 0 << std::endl;
            std::cout << 1 << std::endl;
        }
        else
        {
            double a = 0;
            double b = 1;

            std::cout << 0 << std::endl;
            std::cout << 1 << std::endl;

            for (int i = 0; i < N - 2; i++)
            {
                double c = a + b;
                std::cout << c << std::endl;
                a = b;
                b = c;
            }
        }
        std::cout << "" << std::endl;
    }
    
}
