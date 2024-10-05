#include <iostream>
#include <string>

int Convert(int number, int base);
std::string ConvertToBaseEight(int number, int base);
std::string ConvertToBaseSixteen(int number, int base);

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int number;
    int base;

    while (true)
    {
        std::cout << "Введите число: ";
        std::cin >> number;
        std::cout << "Введите основание, в которое хотите перевести: ";
        std::cin >> base;

        if (Convert(number, base) == 0)
        {
            break;
        }
    }

    return 0;
}

int Convert(int number, int base)
{
    std::string convertedNumber;

    switch (base)
    {
        case 8:
            convertedNumber = ConvertToBaseEight(number, base);
            break;
        case 16:
            convertedNumber = ConvertToBaseSixteen(number, base);
            break;
        default:
            std::cout << "Неизвестная система счисления" << std::endl;
            return 1;
    }

    std::cout << convertedNumber;
    return 0;
}

std::string ConvertToBaseEight(int number, int base)
{
    std::string eightBaseNumber;

    while (number > 0)
    {
        eightBaseNumber = std::to_string(number % base) + eightBaseNumber;
        number = number / base;
    }

    return eightBaseNumber;
}

std::string ConvertToBaseSixteen(int number, int base)
{
    std::string sixteenBaseNumber;
    int modulo;

    while (number > 0)
    {
        modulo = (number % base);

        switch (modulo)
        {
            case 10:
                sixteenBaseNumber = "A" + sixteenBaseNumber;
                break;
            case 11:
                sixteenBaseNumber = "B" + sixteenBaseNumber;
                break;
            case 12:
                sixteenBaseNumber = "C" + sixteenBaseNumber;
                break;
            case 13:
                sixteenBaseNumber = "D" + sixteenBaseNumber;
                break;
            case 14:
                sixteenBaseNumber = "E" + sixteenBaseNumber;
                break;
            case 15:
                sixteenBaseNumber = "F" + sixteenBaseNumber;
                break;
            default:
                sixteenBaseNumber = std::to_string(modulo) + sixteenBaseNumber;
                break;
        }

        number = number / base;
    }

    return sixteenBaseNumber;
}


