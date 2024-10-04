#include <iostream>

int main()
{
    int n = 0;
    std::cout << "N:";
    std::cin >> n;
    std::cout << "8: ";
    std::cout << std::oct << n;
    std::cout << "  16: ";
    std::cout << std::hex << n;
}