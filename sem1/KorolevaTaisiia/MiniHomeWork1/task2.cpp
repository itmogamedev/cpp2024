#include <iostream>

/*Реализовать функцию, которая возвращает подсчет площади трапеции.*/


double trapezoidArea(double base1, double base2, double height) {
    return (base1 + base2) / 2 * height;
}

int main() {

    std::cout << trapezoidArea(2, 4, 3) << std::endl;
    return 0;
}


