#include <iostream>

int main()
{
    int n = 0;
    std::cout << "N:";
    std::cin >> n;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        }
        else {
            n = ((n * 3) + 1) / 2;
        }
    }
    if (n == 1) {
        std::cout << "Dokazano";
    }
}