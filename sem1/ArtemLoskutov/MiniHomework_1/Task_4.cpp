#include <iostream>



int main()
{
    unsigned long int number, reverse;
    std::cout << "Enter the number: ";
    std::cin >> number;

    reverse = number % 10;
    number /= 10;
    while (number > 0)
    {
        reverse = reverse * 10 + number % 10;
        number /= 10;
    }
    std::cout << "Reverse = " << reverse;
}
