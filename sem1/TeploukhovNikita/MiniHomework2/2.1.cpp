#include <iostream>

int num_input = 0;

int main()
{
    std::cout << "Converting your decimal to octal and hex" << std::endl;
    std::cout << "Enter your decimal number: ";
    std::cin >> num_input;
    std::cout << "Your number in octal: " << std::oct << num_input << std::endl;
    std::cout << "Your number in hex: " << std::hex << num_input << std::endl;
}