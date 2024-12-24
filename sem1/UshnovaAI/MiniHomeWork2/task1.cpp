#include <iostream>

int main()
{
    while (1) {
        std::cout << "Select octal and hexadecimal number system\nWrite 8 or 16\n";
        int numSys, num;
        std::cin >> numSys;
        if ((numSys == 16) or (numSys == 8)) {
            std::cout << "Enter your number:\n";
            std::cin >> num;
            switch (numSys) {
            case 16:
                std::cout << "Hexadecimal number: " << std::hex << num << std::endl;
                break;
            case 8:
                std::cout << "Octal number: " << std::oct << num << std::endl;
                break;
            }
        }
        else {
            std::cout << "Invalid input\n";
        }

    }
    return 0;
}