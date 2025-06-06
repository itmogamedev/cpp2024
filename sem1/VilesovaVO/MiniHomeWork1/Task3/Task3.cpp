#include <iostream>

int main()
{
    int a, b, c,  n;
    std::cout << "Enter a number of element :\n";
    std::cin >> n; 
    a = 0;
    b = 1;
    n -= 2;
    std::cout << "0\n" << "1\n";
    while (n > 0)
    {

        c = a + b;
        a = b;
        b = c;
        n--;
        std::cout << c << std::endl;

    }

}