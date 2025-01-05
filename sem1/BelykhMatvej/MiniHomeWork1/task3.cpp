#include <iostream>

void FibonacciNum(int n) {
    int NumOne = 0, NumTwo = 0, SumN = 1;
    if (n > 0) {
        std::cout << "0 ";
    }

    if (n < 0) {
        std::cout << "Error: The input number cannot be negative" << std::endl;
    }

    else {
        n -= 1;
        for (int i = 1; i <= n; i++) {
            std::cout << SumN << " ";
            NumTwo = NumOne;
            NumOne = SumN;
            SumN = NumOne + NumTwo;
        }
        std::cout << std::endl;
    }
}

int main() {
    int a;
    std::cin >> a;
    FibonacciNum(a);
}