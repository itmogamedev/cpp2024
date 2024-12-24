#include <iostream>
double trap(double a, double b, double h) {
    return(((a+b)*h)/2);
}

int main()
{
    setlocale(LC_ALL, "rus");
    double a;
    double b;
    double h;
    std::cin >> a >> b >> h;
    std::cout <<"Площадь трапеции: "<<trap(a,b,h);
}


