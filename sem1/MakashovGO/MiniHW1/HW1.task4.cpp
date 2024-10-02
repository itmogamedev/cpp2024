#include <iostream>


int main()
{
    int n;
    std::cout << "Enter the number to convert: ";
    std::cin >> n;
    while (n % 10 == 0)
    {
        n /= 10;
    }
    while (n != 0)
    {
        std::cout << n % 10;
        n /= 10;
    }
}