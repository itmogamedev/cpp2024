#include <iostream>

long int Reverse()
{
    long int n, ost;
    long int reverse = 0;
    std::cout << "Enter a number: ";
    std::cin >> n;
    while (n > 0)
    {
        ost = n % 10;
        reverse = reverse * 10 + ost;
        n /= 10;
    }
    std::cout << reverse;
    return 0;
}  
int main() 
{
    Reverse();
}
