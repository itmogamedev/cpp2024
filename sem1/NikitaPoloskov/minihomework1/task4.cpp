#include <iostream>

int main()
{
    int number;
    std::cin >> number;

    if (number < 0)
    {
        std::cout << "-";
        number *= -1;
    }

    do
    {
        std::cout << number%10;
        number /= 10;
    } while (number);
}