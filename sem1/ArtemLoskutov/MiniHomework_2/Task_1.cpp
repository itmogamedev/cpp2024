#include <iostream>



int main()
{
    std::cout << "To stop write -1" << std::endl;
    while (true)
    {
        unsigned int number;
        std::cout << "Write the number to convert to 8 and 16 number systems: ";
        std::cin >> number;
        if (number == -1) break;
        std::cout << "In octal number system: " << std::oct << number << std::endl;
        std::cout << "In hexadecimal number system: " << std::hex << number << std::endl << std::endl;
    }
}
