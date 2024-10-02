#include <iostream>

void trp_area()
{
    int trp_lside;
    int trp_uside;
    int trp_h;
    std::cout << "Enter lower side of trapezoid";
    std::cin >> trp_lside;
    std::cout << "Enter upper side of trapezoid";
    std::cin >> trp_uside;
    std::cout << "Enter trapezoid heigh";
    std::cin >> trp_h;
    std::cout << "Trapezoid area: " << float((trp_lside + trp_uside)*trp_h)/2;
}
int main()
{
    trp_area();
    return 0;
}
