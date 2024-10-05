#include <iostream>
#include <string>

std::string transformBase(int number, int base) {

    std::string bases = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string result = "";

    while (number > 0) {
        result = bases[number % base] + result;
        number /= base;
    }
    return result;
}



int main()
{
    int decimal;
    std::cout << "Enter decimal to convert to hex/oct: ";
    std::cin >> decimal;
    std::cout << "Hexdecimal: " << transformBase(decimal, 16) << std::endl;
    std::cout << "Octal: " << transformBase(decimal, 8) << std::endl;
    return 0;
}

