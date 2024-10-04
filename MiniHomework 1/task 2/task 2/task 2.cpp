#include <iostream>

int main()
{
    int H = 0;
    int a = 0;
    int b = 0;
    std::cout << "H: ";
    std::cin >> H ;
    std::cout << "A:";
    std::cin >> a ;
    std::cout << "B:";
    std::cin >> b ;
    std::cout << ((a + b) / 2) * H ;
    return 0;
}