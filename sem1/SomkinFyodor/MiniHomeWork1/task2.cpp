#include <iostream>

long double ploshad(long double height, long double basis1, long double basis2) {
    long double squaretrapezoid;
    squaretrapezoid = height * ((basis1+basis2)/2);
    return squaretrapezoid;

}

int main()
{
    long double height, basis1, basis2;
    long double squaretrapezoid;
    std::cin >> height >> basis1 >> basis2;
    squaretrapezoid = ploshad(height, basis1, basis2);
    std::cout << squaretrapezoid;
}

