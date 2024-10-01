#include <iostream>



int main()
{
    unsigned int number;
    std::cout << "Enter a number to test the Syracuse hypothesis: ";
    std::cin >> number;
    while (number > 1)
    {
        if (number % 2 == 0)
        {
            number /= 2;
            std::cout << number << std::endl;
        }
        else
        {
            number = (number * 3 + 1) / 2;
            std::cout << number << std::endl;
        }
    }
}
