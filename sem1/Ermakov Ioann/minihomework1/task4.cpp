

#include <iostream>

int Revert(int a)
{
    int b = 0;
    while (a > 0) {
        b = b * 10;
        b = (a % 10) + b;
        a = a / 10;
    }
    return b;
}
int main()
{
    int a = 0;
    std::cin >> a;
    std::cout << Revert(a);
}