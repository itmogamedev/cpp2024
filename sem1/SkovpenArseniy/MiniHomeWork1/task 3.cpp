#include <iostream>

int main()
{
    setlocale(LC_ALL, "RU");
    int n=0,i=0,a=0,b=1,c=0;
    std::cout << "Введите количетво чисел Фибоначчи:";
    std::cin >> n;
    while (i < n) {
        a = b;
        b = c;
        c = a + b;
        std:: cout << c << " ";
        i++;

    }
    return 0;
}

