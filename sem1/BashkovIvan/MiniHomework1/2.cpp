#include <iostream>

void trapezoidArea1() {
    float base1, base2, height;
    std::cout << "Please, enter the first base:" << std::endl;
    std::cin >> base1;
    std::cout << "Please, enter the second base:" << std::endl;
    std::cin >> base2;
    std::cout << "Please, enter the height:" << std::endl;
    std::cin >> height;
    std::cout << "The area of the trapezoid: " << height * (base1 + base2) * 0.5;
}

void trapezoidArea2() {
    float midline, height;
    std::cout << "Please, enter the midline:" << std::endl;
    std::cin >> midline;
    std::cout << "Please, enter the height:" << std::endl;
    std::cin >> height;
    std::cout << "The area of the trapezoid: " << midline * height;
}

void trapezoidArea3() {
    float diagonal1, diagonal2, sine;
    std::cout << "Please, enter the first diagonal:" << std::endl;
    std::cin >> diagonal1;
    std::cout << "Please, enter the second diagonal:" << std::endl;
    std::cin >> diagonal2;
    std::cout << "Please, enter the sine of the angle between the diagonals:" << std::endl;
    std::cin >> sine;
    std::cout << "The area of the trapezoid: " << diagonal1 * diagonal2 * sine * 0.5;
}

int main() {
    int choice;
    std::cout << "If you want to find the area of the trapezoid using two bases and the height, please, enter 1" << std::endl;
    std::cout << "If you want to find the area of the trapezoid using the midline and the height, please, enter 2" << std::endl;
    std::cout << "If you want to find the area of the trapezoid using two diagonals and the angle between them, please, enter 3" << std::endl;
    std::cin >> choice;
    if (choice == 1) {
        trapezoidArea1();
    }
    else if (choice == 2) {
        trapezoidArea2();
    }
    else if (choice == 3) {
        trapezoidArea3();
    }
    else {
        std::cout << "You must have made a mistake. Please, rerun the program.";
    }
}