#include <iostream>

int main() {
    
    int input = 0;
    int mode = 0;
    std::cout << "Enter a decimal number (>= 0) for conversion: ";
    std::cin >> input;
    if (input<0)
    {
        std::cout<< std::endl <<"Less than 0!";
        return -1;
    }
    
    std::cout << std::endl;
    std::cout << "For hexadecimal conversion, enter '1'. For octal conversion, enter '2'. Any other input will cause a programm to exit." << std::endl << "Your input: ";
    std:: cin >> mode;

    switch (mode)
    {
    case 1:
        std::cout << "Hexadecimal: " << std::hex << input << std::endl;
        break;
    case 2:
        std::cout << "Octal: " << std::oct << input << std::endl;
        break;
    default:
        return -1;
    }
}