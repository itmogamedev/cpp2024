#include <iostream>

void fun(int number)
{
    while (number != 1)
    {
        if (number % 2 == 0)
        {
            number = number / 2;
        }
        else if (number % 2 == 1)
        {
            number = number * 3 + 1;
        }
    }
    
    std::cout << number << std::endl;
}

int main()
{
    int number;

    std::cout << "Введите число" << std::endl;
    std::cin >> number;

    fun(number);
}