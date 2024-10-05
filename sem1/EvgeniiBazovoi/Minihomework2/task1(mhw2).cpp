

#include <iostream>

int main()
{
    int i;
    std::cout << "choose a number system from 8 and 16!\n";
    std::cin >> i;
    int a;
    if (i == 8 ) {
        std::cout << "write a number\n";
        std::cin >> std::oct >> a;
        std::cout << a;
    }
    if (i == 16) {
        std::cout << "write a number\n";
        std::cin >> std::hex >> a;
        std::cout << a;
    }
}
