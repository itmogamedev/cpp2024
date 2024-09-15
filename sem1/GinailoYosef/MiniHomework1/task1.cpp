#include <iostream>

int getSquareArea(int squareSide){
    return squareSide * squareSide;
};

int main(){
    int squareSide;
    std::cin >> squareSide;
    std::cout << getSquareArea(squareSide);
};