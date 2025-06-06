#include <iostream>


int square_area(int side) {
    int area = side * side;
    return area;
}

int main()
{
    int side;

    std::cout << "Enter square side: ";
    std::cin >> side;

    std::cout << "Square area: " << square_area(side) << std::endl;
}
