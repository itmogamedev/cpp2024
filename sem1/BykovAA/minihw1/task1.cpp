#include <iostream>

float FindSquareArea(float squareSide);

int main()
{
    setlocale(LC_ALL, "Russian");

    float squareSide;

    while(true)
    {
        std::cout << "Вdедите длину стороны квадрата: ";
        std::cin >> squareSide;

        if (squareSide > 0)
        {
            std::cout << "Площадь квадрата = " << FindSquareArea(squareSide);
            break;
        }
        else
        {
            std::cout << "Некорректный ввод!" << std::endl;
        }
    }

    return 0;
}

float FindSquareArea(float squareSide)
{
    float area;

    area = squareSide * squareSide;

    return area;
}