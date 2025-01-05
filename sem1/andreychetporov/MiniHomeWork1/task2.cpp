#include <iostream>

int square(float high, int side1, int side2) {
    return high * (side1 + side2) / 2;
}


int main()
{
    float high; int side1; int side2;
    std::cin >> high >> side1 >> side2;
    std::cout << square(high, side1, side2);
}
