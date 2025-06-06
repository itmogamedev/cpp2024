#include <iostream>

int FindFiboElement(int elementNumber);

int main()
{
    setlocale(LC_ALL, "Russian");

    int elementNumber;

    std::cout << "Введите сколько чисел Фибоначи вы хотите вывести: ";
    std::cin >> elementNumber;

    for (int i = 1; i <= elementNumber; i++)
    {
        std::cout << FindFiboElement(i) << std::endl;
    }

    return 0;
}

int FindFiboElement(int elementNumber)
{
    int fiboNumber;

    switch (elementNumber)
    {
        case 1:
            fiboNumber = 0;
            break;
        case 2:
            fiboNumber = 1;
            break;
        default:
            fiboNumber = FindFiboElement(elementNumber - 2) + FindFiboElement(elementNumber - 1);
            break;
    }

    return fiboNumber;
}