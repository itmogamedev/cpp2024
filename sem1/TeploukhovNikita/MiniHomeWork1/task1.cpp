#include <iostream>

int sqr_side;

int count_sqr_area(int side);

int main()
{
    std::cout << "Square area calculation" << std::endl;
    std::cout << "Enter square side: ";
    std::cin >> sqr_side;
    std::cout << "Area of square: " << count_sqr_area(sqr_side);

    return 0;
}

int count_sqr_area(int side)
{
    return side * side;
}