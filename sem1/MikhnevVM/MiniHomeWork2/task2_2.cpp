
#include <iostream>

int main()
{
    int number, main_menu;
    while (1==1)
    {
        std::cout << "Введите число и я проверю для него гипотезу Сиракуз" << '\n';
        std::cin >> number;
        while (number != 1)
        {
            if (number%2==0)
            {
                number/=2;
                std::cout << number << '\n';
            }else
            {
                number = (number * 3 + 1)/2;
                std::cout << number << '\n';
            }
        
        }
        std::cout << '\n';
        std::cout << "Для этого числа теория Сиракуз работает" << '\n';
        std::cout << "Если вы хотите завершить работу программы введите 0, иначе введите 1" << '\n';
        std::cin >>  main_menu;
        if (main_menu == 0)
        {
            break;
        }
    
        
    }
}