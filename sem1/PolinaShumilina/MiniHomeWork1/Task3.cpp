#include <iostream>

int main()
{
    int x = 0;
    int y = 1;
    int z;
    int n;
    std::cout << "Enter the number of elements - ";
    std::cin >> n;
    std::cout << 1 << " ";
    for (int i = 0; i < n - 1;++i) {
        z = x + y;
        x = y;
        y = z;
        std::cout << z << " ";
    }
}
