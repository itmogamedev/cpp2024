#include <iostream>

void transformation (int user_number) {
    std::cout << "hexadecimal base: " << std::hex << user_number << std::endl;
    std::cout << "octal base: " << std::oct << user_number << std::endl;
}

int main()
{
    int user_number;
    std::cout << "Enter the number" << std::endl;
    std::cin >> user_number;
    transformation (user_number);
    return 0;
}