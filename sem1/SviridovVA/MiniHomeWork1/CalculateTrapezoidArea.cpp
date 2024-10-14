#include <cassert>

double CalculateTrapezoidArea(int a, int b, int h) {
    if (a < 0 || b < 0 || h < 0) {return -1;}

    return ((a + b) / 2.0) * h;
}

void Test() {
    assert(CalculateTrapezoidArea(2, 4, 7) == 21);
    assert(CalculateTrapezoidArea(-1, -1, -1) == -1);
    assert(CalculateTrapezoidArea(2, 4, 0) == 0);
}

int main() {
    Test();
}