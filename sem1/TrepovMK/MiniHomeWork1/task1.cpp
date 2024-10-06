#include <iostream>

void sqr_area()
{
    int sqr_side;
    std::cout << "Enter square side";
    std::cin >> sqr_side;
    std::cout << "Square area: " << sqr_side * sqr_side;
}
int main()
{
    sqr_area();
    return 0;
}
