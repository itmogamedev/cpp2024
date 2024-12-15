#include <iostream>

int square(int n) {
    return n * n;

}

int main()
{
    int n;
    std::cin >> n;
    std::cout << square(n);
}