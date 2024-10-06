#include <iostream>


float trapezoid(int TopSide, int DownSide, int H ) {
    return (TopSide + DownSide) * H/2;
}

int main()
{
    int InputTop;
    int InputDown;
    int InputH;
    std::cout << "Enter the lenght of the top side of trapezoid (>0) ";
    std::cin >> InputTop;
    std::cout << "Enter the lenght of the down side of trapezoid (>0) ";
    std::cin >> InputDown;
    std::cout << "Enter the lenght of the Height of trapezoid (>0) ";
    std::cin >> InputH;
    std::cout << "The Area of trapezoid is " << trapezoid(InputTop, InputDown, InputH);
}