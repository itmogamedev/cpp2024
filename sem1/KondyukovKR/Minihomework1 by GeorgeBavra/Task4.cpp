#include <iostream>

int main()
{
    int x = 0;
    int y = 0;
    std::cout << "¬ведите число";
    std::cin >> x;
    for (x > 9); {
        y = y * 10 + x % 10;
        x = x / 10;
    }
    std::cout << y;
    return 0;
}