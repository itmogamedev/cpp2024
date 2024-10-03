#include <iostream>

void printFibonacciList(int elementsAmount){
    int twoStepsBackNum = 0;
    int oneStepBackNum = 1;

    if (elementsAmount >= 1){ std::cout << twoStepsBackNum << " "; };
    if (elementsAmount >= 2){ std::cout << oneStepBackNum << " "; };

    for (int i = 2; i < elementsAmount; i++){
        int currentResult = oneStepBackNum + twoStepsBackNum;

        std::cout << currentResult << " ";

        twoStepsBackNum = oneStepBackNum;
        oneStepBackNum = currentResult;
    };
};

int main(){
    int elementsAmount;
    std::cin >> elementsAmount;
    printFibonacciList(elementsAmount);
};