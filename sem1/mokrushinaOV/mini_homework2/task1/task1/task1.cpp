#include <iostream>
#include <string>

char althabet[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

std::string to_octal(int num, int syst) {
    std::string res = "";

    while (num > 0) {
        res = althabet[num % syst] + res;
        num /= syst;
    }

    return res;
}

int main()
{
    int syst, num;

    std::cout << "enter the number system from 2 to 36: ";
    std::cin >> syst;
    std::cout << std::endl;

    std::cout << "enter decimal non-negative number you want to transfer to this number system: ";
    std::cin >> num;
    std::cout << std::endl;

    std::cout << "your transfered number: " << to_octal(num, syst) << std::endl;

    return 0;
}