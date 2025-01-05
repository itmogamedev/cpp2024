#include <iostream>

int reverseNumber(int number) 
{
    int rnumber = 0;
    while (number != 0) 
    {
        rnumber *= 10;
        rnumber += number % 10;
        number /= 10;
    }
    return rnumber;
}

int main() 
{
    int number;

    std::cout << "Введите любое число, чтобы его развернуть: ";
    std::cin >> number;

    int rnumber = reverseNumber(number);

    std::cout << "Число после разворота: " << rnumber << std::endl;

    return 0;
}
