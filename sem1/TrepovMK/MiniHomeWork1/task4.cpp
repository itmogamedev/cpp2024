#include <iostream>

int main()
{
    int num;
    std::cout << "Enter number to reverse";
    std::cin >> num;
    for (;num > 0;num = num / 10) 
    {
        std::cout << num % 10;
    }
}
