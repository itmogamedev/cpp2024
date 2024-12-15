#include <iostream>


int Fibo() 
{
    int n = 0;
    int i = 0;
    int a = 0;
    int b = 1;
    int c = 0;

    std::cout << "Enter how many Fibonachi numbers you want:";
    std::cin >> n;
    while (i < n) 
    {       
        a = b;
        b = c;
        c = a + b;
        std::cout << c <<", ";
        i++;
    }
    return 0;
}

int main()
{
    Fibo();
}