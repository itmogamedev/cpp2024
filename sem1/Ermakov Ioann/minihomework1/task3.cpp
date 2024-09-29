

#include <iostream>

int Fibon(int n)
{
    ;
    int a = 0, b = 1;
    int coc = a;

    for (int i = 1; i <= n; i++)
    {
        std::cout << a << " ";
        coc = a + b;
        a = b;
        b = coc;
    }
    return b;
}
int main()
{
    int h;
    std::cin >> h;
    Fibon(h);

}

