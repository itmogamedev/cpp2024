#include <iostream>

int fib(int x) {
    if (x == 1)
        return 0;
    if (x == 2)
        return 1;
    return fib(x - 2) + fib(x - 1);
}
int main()
{
    //Задание 3
    int n;
    std::cout << "3) n = ";
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cout << fib(i) << ' ';
    }
    std::cout << '\n';
}