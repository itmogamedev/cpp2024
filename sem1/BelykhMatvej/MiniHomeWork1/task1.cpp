#include <iostream>

float SquareArea(float a) {
    return(a * a);
}

int main() {
    int a;
    std::cin >> a;
    std::cout << SquareArea(a) << std::endl;
}