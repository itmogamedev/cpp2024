#include <iostream>



int main()
{
    long int n, a = 1, b = 1;
    std::cout << "Enter the desired number of Fibonacci series elements: ";
    std::cin >> n;

    while (n > 0)
    {
        std::cout << a << std::endl;
        if (n != 1)
        {
            std::cout << b << std::endl;
        }

        a = a + b;
        b = b + a;
        n = n - 2;
    }
}
