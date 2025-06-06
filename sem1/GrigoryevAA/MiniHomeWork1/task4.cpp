#include <iostream>

int main()
{
    long long N = 0;
    while (true)
    {
        std::cout << "Enter number: ";
        std::cin >> N;
        std::cout << "" << std::endl;
        if (N == 0)
        {
            std::cout << "0";
        }
        else
        {
            while (N > 0)
            {
                std::cout << N % 10;
                N /= 10;
            }
        }
        std::cout << "" << std::endl;
        std::cout << "" << std::endl;
    }
    
}
