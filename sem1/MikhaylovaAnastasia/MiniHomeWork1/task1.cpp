

#include <iostream>

double square(double a) {
    return a * a;
}

int main()
{ 
    setlocale(LC_ALL, "rus");
    double a;
    std::cin>>a;
    std::cout << "Площадь квадрата:" << square(a);
}

