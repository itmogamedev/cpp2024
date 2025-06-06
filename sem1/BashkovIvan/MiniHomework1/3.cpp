#include <iostream>

void fibonacciSequence(long long int N) {
    int currentElem, prepreviousElem = 0, previousElem = 1, currentNumber = 0;
    while (currentNumber < N) {
        if (currentNumber == 0) {
            std::cout << 1;
        }
        else {
            currentElem = prepreviousElem + previousElem;
            std::cout << " " << currentElem;
            prepreviousElem = previousElem;
            previousElem = currentElem;
        }
        currentNumber++;
    }
}

int main() {
    long long int N;
    std::cout << "Please, enter N:" << std::endl;
    std::cin >> N;
    std::cout << "First " << N << " numbers of the Fibonacci sequence:" << std::endl;
    fibonacciSequence(N);
}