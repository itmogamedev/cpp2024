#include <iostream>

static float TrapezoidArea(float UpperSide, float LowerSide, float Height) {
    return ((UpperSide+LowerSide)*Height)/2;
}

int main() {
    int InputUpperSide;
    int InputLowerSide;
    int Height;
    std::cout << "Enter the length of the upper base of the trapezoid: ";
    std::cin >> InputUpperSide;
    std::cout << "Enter the length of the lower base of the trapezoid: ";
    std::cin >> InputLowerSide;
    std::cout << "Enter the height of the trapezoid: ";
    std::cin >> Height;

    float Area = TrapezoidArea(InputUpperSide, InputLowerSide, Height);
    std::cout << "Trapezoid area: " << Area;

    return 0;
}