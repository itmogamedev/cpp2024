#include <iostream>

int main()
{
    float A = 0;
    float B = 0;;
    float h = 0;
    std::cout << "Enter base a ";
    std::cin >> A;
    std::cout << "Enter base b ";
    std::cin >> B;
    std::cout << "Enter height ";
    std::cin >> h;
    std::cout << "Area of trapezium = " << (A + B) * h * 0.5;
}
