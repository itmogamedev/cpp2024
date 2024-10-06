#include <iostream>

int main()
{
    setlocale(LC_ALL, "RUS");
    int number;
    std::cout << "введите число в десятичной ";
    std::cin >> number;
    std::cout << "число в восьмеричной: " << std::oct << number << '\n';
    std::cout << "число в шестнадцатиричной: " << std::hex << number;
}
