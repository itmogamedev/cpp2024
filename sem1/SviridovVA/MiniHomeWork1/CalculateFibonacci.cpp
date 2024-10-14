#include <iostream>
#include <vector>

std::vector<int> CalculateFibonacci(int N) {
    if (N <= 0) {return {};};
    if (N == 1) {return {0};}

    std::vector<int> fibonacci_array = {0, 1};

    for(int i = 2; i < N; ++i) {
        fibonacci_array.push_back(fibonacci_array[i - 2] + fibonacci_array[i - 1]);
    }

    return fibonacci_array;
}

void print(const std::vector<int>& array) {
    for (int i : array) {
        std::cout << i << ' ';
    }
}

int main() {
    int N; std::cin >> N;

    print(CalculateFibonacci(N));
}
