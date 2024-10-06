#include <iostream>

int main()
{
    int i;
    std::cout << "Enter the number. The first number will be in octal system and second number will be in hexadecimal system ";
    std::cin >> i;
    std::cout << std::oct << i << std::endl;
    std::cout << std::hex << i;
}
