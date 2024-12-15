#include <iostream>
int main()
{
    std::cout << "Возьмём любое натуральное число " << std::endl;
    std::cout << "Если оно чётное - разделим его пополам, если" << std::endl;
    std::cout << "нечётное - умножим на 3, прибавим 1 и разделим пополам" << std::endl;
    std::cout << "Повторим эти действия с вновь полученным числом." << std::endl;
    std::cout << "Гипотеза гласит, что независимо от выбора первого числа" << std::endl;
    std::cout << "рано или поздно мы получим 1" << std::endl;
    std::cout << "Проверим гипотезу Сиракуз" << std::endl;
    std::cout << "Введите натуральное число" << std::endl;
    int number = 0;
    do {
    std::cin >> number;
    if (number > 0) {
    while (number != 1) {
        if (number % 2 == 0) {
            std::cout << "Разделим число пополам" << std::endl;
            number /= 2;
        } else {
            std::cout << "Умножим число на 3, прибавим 1 и разделим число пополам" << std::endl;
            number = ((number * 3) + 1) / 2;
        }
        std::cout << number << std::endl;
    }
    std::cout << "Гипотеза Сиракуз доказана" << std::endl;
    } else {
        std::cout << "Это не натуральное число" << std::endl;
    }
    } while (number <= 0);
}