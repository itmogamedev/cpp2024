#include <iostream>

int main()
{
    int a, b = 0, i = 1, j = 1, c;
    std::cin >> a;
    c = a;
    c /= 10;
    while(c > 0){
        c /= 10;
        j*=10;
    }
    while (a > 0) {
        b += i*(a / j);
        a %= j;
        j /= 10;
        i *= 10;
    }
    std::cout << b;
}
