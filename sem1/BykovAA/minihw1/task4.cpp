#include <iostream>

int FlipNumber(int number);

int main()
{
    setlocale(LC_ALL, "Russian");

    int number;

    std::cout << "Введите число для преобразования: ";
    std::cin >> number;

    std::cout << FlipNumber(number);

    return 0;
}

int FlipNumber(int number)
{
    int flippedNumber;

    flippedNumber = number % 10;
    number = number / 10;

    while(number > 0)
    {
        flippedNumber = flippedNumber * 10 + number % 10;
        number = number / 10;
    }

    return flippedNumber;
}