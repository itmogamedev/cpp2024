#include <iostream>
#include <iomanip>

std::string toOctal(int number) 
{
    std::string octal;
    while (number > 0) 
    {
        octal = std::to_string(number % 8) + octal;
        number /= 8;
    }
    return octal.empty() ? "0" : octal;
}

std::string toHexadecimal(int number) 
{
    std::string hexadecimal;
    const char hexDigits[] = "0123456789ABCDEF";
    while (number > 0) 
    {
        hexadecimal = hexDigits[number % 16] + hexadecimal;
        number /= 16;
    }
    return hexadecimal.empty() ? "0" : hexadecimal;
}

int main() 
{
    int number;

    std::cout << "Введите число в десятичной системе счисления: ";
    std::cin >> number;

    std::string octal = toOctal(number);
    std::string hexadecimal = toHexadecimal(number);

    std::cout << "Введенное число в восьмиричной системе: : " << octal << std::endl;
    std::cout << "Введенное число в шестнадцатиричной системе: " << hexadecimal << std::endl;

    return 0;
}
