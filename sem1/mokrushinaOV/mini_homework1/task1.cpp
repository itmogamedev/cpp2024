#include <iostream>


int square_area(int side) {
    int area = side * side;
    return area;
}

int main()
{
    std::cout << square_area(3) << std::endl;
}
