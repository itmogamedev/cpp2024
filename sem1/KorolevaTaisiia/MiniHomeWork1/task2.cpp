#include <iostream>

/*Реализовать функцию, которая возвращает подсчет площади трапеции.*/


double trapezoidArea(double base1, double base2, double height) {
    return (base1 + base2) / 2 * height;
}

int main() {
    double base1, base2, height;
    std::cout << "Enter bottom base length \n";
    std::cin >> base1;
    std::cout << "Enter upper base length \n";
    std::cin >> base2;
    std::cout << "Enter height length \n";
    std::cin >> height;
    std::cout << trapezoidArea(base1, base2, height) << std::endl;
    return 0;
}


