#include <iostream>

int main()
{
    int n1, n2;
    std::cout << "Enter the number to convert to hex - ";
    std::cin >> n1;
    std::cout << std::hex << n1 << std::endl;
    std::cout << "Enter the number to convert to oct - ";
    std::cin >> n2;
    std::cout << std::oct << n2 << std::endl;
}

