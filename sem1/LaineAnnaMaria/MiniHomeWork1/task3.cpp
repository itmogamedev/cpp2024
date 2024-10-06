#include <iostream>

int main()
{
    int a = 0;
    int b = 1;
    int c;
    int input;
    std::cout << "Enter sequence length ";
    std::cin >> input;
    std::cout << 1 << " ";
    for (int i = 0; i < input - 1; i++) {
        c = a + b;
        a = b;
        b = c;
        std::cout << c << " ";
    }
}