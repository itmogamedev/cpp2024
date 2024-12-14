#include <iostream>

int ReverseOrder(int n) {
    int new_num = 0;
    while (n != 0) {
        new_num = new_num * 10 + n % 10;
        n /= 10;
    }
    return new_num;
}

int main()
{
    int num = 0;
    std::cin >> num;
    std::cout << ReverseOrder(num);
    return 0;
}