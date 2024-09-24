#include <iostream>

int main()
{
    int side_1;
    setlocale(LC_ALL, "Russian");
    std::cout<<"Введите сторону квадрата:";
    std::cin>> side_1;
    
    int Square_Area = side_1 * side_1;
    
    std::cout<<Square_Area;

    return 0;
}