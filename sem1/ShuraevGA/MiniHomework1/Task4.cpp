#include <iostream>


int main()
{
    int old;
    int NewNum = 0;
    std::cout << "Enter your number to ~reverse~ ";
    std::cin >> old;
    while (old != 0) {
        NewNum = (NewNum * 10) + old % 10;
        old /= 10;
    }
    std::cout << "Reverse completed! Now your number is " << NewNum;
}
