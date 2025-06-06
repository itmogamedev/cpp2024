#include <iostream>

/*Task1: Реализовать функцию, которая возвращает подсчет площади квадрата.*/

double sqr_area(double square_side) {
    return square_side * square_side;
}

int main() {
    double sqr_a;
    std::cout << "Enter square side \n";
    std::cin >> sqr_a;
    std::cout << "S = " << sqr_area(sqr_a) << std::endl;
    return 0;
}
