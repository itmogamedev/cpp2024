#include <iostream>

int getTrapezoidArea(int sideA, int sideB, int height){
    return (sideA + sideB) * height / 2;
}

int main(){
    int sideA, sideB, height;
    std::cin >> sideA, sideB, height;
    std::cout << getTrapezoidArea(sideA, sideB, height);
};