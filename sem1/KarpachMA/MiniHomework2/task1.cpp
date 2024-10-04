#include <iostream>
int main()
{
    int userChoice = 0;
    int number = 0;
    std::cout << "Введите число в десятичной системе счисления" << std::endl;
    std::cin >> number;
    std::cout << "Введите систему счисления, в которую вы хотите перевести число (8-ричная/16-ричная)" << std::endl;
    do {
    std::cin >> userChoice;
    if (userChoice == 16){
        std::cout << std::hex << number;
        break;
    }
    else if (userChoice == 8)
    {
        std::cout << std::oct << number;
        break;
    }
    else
    {
        std::cout << "Это не 16-ричная и не 8-ричная система счисления, введите корректную систему счисления" << std::endl;
    }
    } while (userChoice != 8 || userChoice != 16);
}