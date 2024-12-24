#include<iostream>


double SquareArea(double a) {
    return a * a;

}

int main()
{
    double a;
    do {
        std::cout << "Enter square side: ";
        std::cin >> a;
        if (a <= 0) {
            std::cout << "Side can't be - or 0" << std::endl;
        }
    } while (a <= 0);

    std::cout << "Square area is: " << SquareArea(a);
    return 0;
}

