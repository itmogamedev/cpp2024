#include <iostream>

void SirakuzHyp(long long number);

int main()
{
    setlocale(LC_ALL, "RU");

    std::cout << "Введите число: ";
    long long number;
    std::cin >> number;

    SirakuzHyp(number);
}

void SirakuzHyp(long long number)
{
    long long n = number;
    int i = 0;
    do
    {
        if (number % 2 == 0)
        {
            number /= 2;
            std::cout << number << std::endl;
            ++i;
        }
        else
        {
            number *= 3;
            ++number;
            std::cout << number << std::endl;
            ++i;
        }

    } while (number != 1);

    std::cout << "Для числа " << n << " потребовалось операций: " << i;
}


