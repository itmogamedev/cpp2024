#include <iostream>
using std::cin;
using std::cout;


int main()
{
    int n;
    cin >> n;
    while (n % 10 == 0)
    {
        n /= 10;
    }
    while (n != 0)
    {
        cout << n % 10;
        n /= 10;
    }
}