#include <iostream>

float TrapezoidArea(float a, float b, float h) {
    return(((a + b) / 2) * h);
}

int main() {
    int a,b,h;
    std::cin >> a >> b >> h;
    std::cout << TrapezoidArea(a,b,h) << std::endl;
}