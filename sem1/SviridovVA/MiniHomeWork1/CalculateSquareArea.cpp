#include <cassert>

int CalculateSquareArea(int square_side_length) {
    if (square_side_length < 0) {return -1;}

    return square_side_length * square_side_length;
}

void Test(){
    assert(CalculateSquareArea(0) == 0);
    assert(CalculateSquareArea(5) == 25);
    assert(CalculateSquareArea(-5) == -1);
}

int main() {
    Test();
}
