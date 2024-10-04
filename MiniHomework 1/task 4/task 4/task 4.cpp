#include <iostream>

int main()
{
    int old = 0;
    int n = 0;
    std::cout << "Enter a number: ";
    std::cin >> old ;
    while (old>0)
    {
        n= n * 10 + old % 10;
        old /= 10;
    }
    std::cout << n;
}
