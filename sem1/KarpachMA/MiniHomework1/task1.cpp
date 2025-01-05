#include <iostream>
int findSquareSpace(int squareSide);
int main()
{
    int squareSide = 0;
    std::cout << "Введите размер стороны квадрата" << std::endl;
    std::cin >> squareSide;
    std::cout << "Площадь квадрата равна " << findSquareSpace(squareSide);
}
int findSquareSpace(int squareSide){
    return squareSide * squareSide;
}