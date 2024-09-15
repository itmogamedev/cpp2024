#include <iostream>

/*Task1: Реализовать функцию, которая возвращает подсчет площади квадрата.*/

double sqr_area(double square_side) {
    return square_side * square_side;
}

int main() {

    std::cout << sqr_area(4) << std::endl;
    return 0;
}
