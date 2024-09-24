#include <iostream>

float FindTrapezeArea(float firstBaseLength, float secondBaseLength, float height);

int main()
{
    setlocale(LC_ALL, "Russian");

    float firstBaseLength;
    float secondBaseLength;
    float height;

    while (true)
    {
        std::cout << "Введите длину первого основания трапеции: ";
        std::cin >> firstBaseLength;
        std::cout << "Введите длину второго основания трапеции: ";
        std::cin >> secondBaseLength;
        std::cout << "Введите длину высоты трапеции: ";
        std::cin >> height;

        if (firstBaseLength > 0 && secondBaseLength > 0 && height)
        {
            std::cout << "Площадь квадрата = " << FindTrapezeArea(firstBaseLength, secondBaseLength, height);
            break;
        }
        else
        {
            std::cout << "Некорректный ввод!" << std::endl;
        }
    }

    return 0;
}

float FindTrapezeArea(float firstBaseLength, float secondBaseLength, float height)
{
    float area;

    area = .5f * (firstBaseLength + secondBaseLength) * height;

    return area;
}