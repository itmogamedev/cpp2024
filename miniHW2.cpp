#include <iostream>
int main()
{
    int n;
    bool flag = true;
    std::cout << "Enter a natural number to test the Syracuse hypothesis: ";
    std::cin >> n;
    std::cout << "(" << n << " == " << "n)" << "\n";
    
    while (flag)
    {
        if (n % 2 == 0)
        {
            n /= (int)2;
            std::cout << " Is an even number >> " << "n / 2 = " << n << "\n";
        }
        else
        {
            n *= (int)3;
            std::cout << " Is an odd number >> \n" << "  n * 3 = " << n << "\n";
            n += 1;
            std::cout << "  n + 1 = " << n << "\n";
            n /= (int)2;
            std::cout << "  n / 2 = " << n << "\n";
        }
        std::cout << "Num: " << n << "\n";
        if (n == 1) flag = 0;
    }
    std::cout << "The hypothesis is verified!!!";
    
    return 0;
}