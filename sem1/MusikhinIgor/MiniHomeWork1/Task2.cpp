#include <iostream>

static float TrapezoidArea(float UpperSide, float LowerSide, float Height) {
    return ((UpperSide+LowerSide)*Height)/2;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int InputUpperSide;
    int InputLowerSide;
    int Height;
    std::cout << "¬ведите длину верхнего основани€ трапеции: ";
    std::cin >> InputUpperSide;
    std::cout << "¬ведите длину нижнего основани€ трапеции: ";
    std::cin >> InputLowerSide;
    std::cout << "¬ведите высоту трапеции: ";
    std::cin >> Height;

    float Area = TrapezoidArea(InputUpperSide, InputLowerSide, Height);
    std::cout << "ѕлощадь трапеции: " << Area;

    return 0;
}