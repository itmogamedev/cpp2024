#include <iostream>

int square(int sideLength)
{
    return sideLength * sideLength;
}

int main()
{
    int sideLength;
    std::cout << "Enter the side length of your square: ";
    std::cin >> sideLength;

    std::cout << "Area of your square: " << square(sideLength) << std::endl;
}

