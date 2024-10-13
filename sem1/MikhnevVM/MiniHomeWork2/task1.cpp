#include <iostream>


int main()
{
    int number, operatoin;
    std::cout<<"Введите число, котрое вы хотите перевести в другую сиситему счисления:" << '\n';
    std::cin >> number;
    std::cout<< '\n';
    std::cout<<"Если Вы хотите перевести число в 8СС, введите 1. " << '\n';
    std::cout<<"Если Вы хотите перевести в 16СС, введите 2 " << '\n';
    std::cin >> operatoin;
    std::cout<< '\n';
    while(operatoin != 1 and operatoin != 2)
    {
    std::cout<<"ВЫ ВВЕЛИ НЕ КОРЕКТНУЮ ОПЕРАЦИЮ, ПОВТОРИТЕ ПОПЫТКУ!!!"<< '\n';
    std::cout << '\n';
    std::cout<<"Если Вы хотите перевести число в 8СС, введите 1. " << '\n';
    std::cout<<"Если Вы хотите перевести в 16СС, введите 2  "<< '\n';
    std::cin >> operatoin;
    std::cout<< '\n';

    }
    if (operatoin == 1)
    {
        std::cout<<"Ваше число в 8СС равно: "<< std::oct << number;
    }
    else 
    {
        std::cout<<"Ваше число в 16СС равно: "<< std::hex << number;
    }

}	`