#include <iostream>

void CollatzConjecture(int n)
{
    while (n != 1) 
    {
        if (n == 1) {
            return;
        }
        if (n % 2 == 0) 
        {
            n /= 2;
            std::cout << n << '\n';
        }
        else
        {
            n = (n * 3 + 1);
            std::cout << n << '\n';
        }
    }
}
int main()
{
    int num;
    std::cin >> num;
    CollatzConjecture(num);
}