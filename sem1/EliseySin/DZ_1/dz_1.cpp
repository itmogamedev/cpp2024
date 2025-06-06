#include <iostream>

int calculateSquareArea(int side) 
{
    return side * side;
}

int main() 
{
    int sk;
    std::cout << "Введите сторону квадрата: ";
    std::cin >> sk;
    
    int svk = calculateSquareArea(sk);
    std::cout << "Площадь квадрата: " << svk;
    
    return 0;
}
