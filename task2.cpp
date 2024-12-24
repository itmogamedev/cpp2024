#include <iostream>
#include <string>

void fun(int a)
{
    std::string num = "";

    while (a > 0)
    {
        num = std::to_string(a % 8) + num;
        a = a / 8;
    }

    std::cout << num;
}

int main()
{
    int a;
    std::cin >> a;
    fun(a);
}