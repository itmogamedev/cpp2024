#include <iostream>
void syracuse(int number)
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
    std::cout << number << "  Ого получилось" << std::endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    std::cout << "Гипотеза Сиракуз" << std::endl;
    int number;
    std::cout << "Выберите число" << std::endl;
    std::cin >> number;
    syracuse(number);
}