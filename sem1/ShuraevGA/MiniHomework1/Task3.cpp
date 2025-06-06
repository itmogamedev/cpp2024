#include <iostream>


long int Fibo(int N) {
    if ((N == 1) or (N == 2)) {
        return 1;
    }
    if(N > 2) {
        return Fibo(N - 1) + Fibo(N - 2);
    }
}

int main() {
    int InputN;
    std::cout << "Enter the number of Fibonacci element (>0) ";
    std::cin >> InputN;
    std::cout << "Your element = " << Fibo(InputN);
}
