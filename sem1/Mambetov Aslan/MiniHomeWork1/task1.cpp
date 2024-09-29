#include <iostream>
#include<iomanip>
#include<cmath>


double calcSqrAreaBySide(double sqrSide) {
    return sqrSide * sqrSide;
}

double calcQuadrangleAreaByCoord(std::pair<double, double> point1,
    std::pair<double, double> point2,
    std::pair<double, double> point3,
    std::pair<double, double> point4) {
    return abs(point1.first * point2.second + point2.first * point3.second + point3.first * point4.second + point4.first * point1.second -
        point1.second * point2.first - point2.second * point3.first - point3.second * point4.first - point4.second * point1.first) / 2;
}



int main() {
    setlocale(LC_ALL, "Russian");

    int mode;
    std::cout << "Как вы хотите узнать площадь квадрата? \n Введите 1, если по стороне \n Введите 2, если по координатам вершин \n";
    std::cin >> mode;

    if (mode == 1) {
        double side;
        std::cout << "\nВведите сторону квадрата: ";
        std::cin >> side;
        std::cout << "\nПлощадь заданного квадрата: " << calcSqrAreaBySide(side) << "\n";
    }
    else if (mode == 2) {
        double x1, y1, x2, y2, x3, y3, x4, y4;
        std::cout << "Введите координаты x и y вершин квадрата (по 2 числа на каждой строчке):\n";
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        std::cout << "\nПлощадь заданного квадрата: " << calcQuadrangleAreaByCoord({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 }) << "\n";
    }
    else {
        std::cout << "\nНекорректный режим\n";
    }

    return 0;
}