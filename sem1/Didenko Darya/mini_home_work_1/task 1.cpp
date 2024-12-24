#include <iostream>
float square_area(float lenght) {
    return lenght * lenght;
}


int main()
{
    float lenght;
    std::cout << "Enter a lenght of a square: ";
    std::cin >> lenght;
    std::cout << "The area of the square is: " << square_area(lenght) << std::endl;
}