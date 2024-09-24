#include <iostream>

void fibonachi_row(int n) {

    int first_n = 0, second_n = 1, result_n, i = 0;

    std::cout << "0 1" << " ";

    for (i; i < n - 1; ++i) {
        result_n = first_n + second_n;
        first_n = second_n;
        second_n = result_n;
        std::cout << result_n << " ";
    }
}

int main() {
    int a;
    std::cout << "Enter the lenght of the Fibohachi sequence:" << " ";
    std::cin >> a;
    if (a < 1 || a > 46) {
        std::cout << "Sorry, the programm doesn't work correctly with the value you entered :( " << std::endl;
    }
    else {
        fibonachi_row(a);
    }
}