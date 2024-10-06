#include <iostream>

int main()
{
    int numb;
    int choose;
    std::cout << "Enter number for converting from one system to another: ";
    std::cin >> numb;
    std::cout << "If u want convert in 8 system - enter \"8\". If u want convert in 16 system - enter \"16\": ";
    std::cin >> choose;

    if (numb == 0 or numb > 0) {
        if (choose == 8) {
            std::cout << std::oct << numb;
        }
        if (choose == 16) {
            std::cout << std::hex << numb;
        }
        if (choose != 8 and choose != 16) {
            std::cout << "Error!!!!";
        }
    }
    else {
        std::cout << "U CAN'T DO IT!";
    }
    
}
