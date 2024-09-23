
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int number;
    int new_number = 0;
    std::cout << "введите натуральное число" << std::endl;
    std::cin >> number;
    while (number > 0)
    {
        new_number = new_number * 10 + number % 10;
        number = number / 10;
    }
    std::cout << new_number;

}
